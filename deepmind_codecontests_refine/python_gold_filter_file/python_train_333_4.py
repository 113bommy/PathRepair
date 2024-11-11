n,k=map(int,input().split())
a=list(map(int,input().split()))
num=[0]*(2*10**5+1)
count=[0]*(2*10**5+1)
a.sort()
for i in a:
    j=i
    t=0
    while(j!=0):
        if num[j]<k:
            num[j]+=1
            j=int(j/2)
            t+=1
            if num[j]<k:
                count[j]+=t
        else:
            j=int(j//2)
m=100000000
for i in range(len(num)):
    if num[i]==k:
        if count[i]<m:
            m=count[i]
print(m)











