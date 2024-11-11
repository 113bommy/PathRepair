n=int(input())
a=list(map(int,input().split()))
c=0
po=[0]*1000000
ne=[0]*1000000
for i in range(n):
    if(a[i]<0 and ne[a[i]]!=1):
        c+=1
        ne[a[i]]=1
    elif(a[i]>0 and po[a[i]]!=1):
        c+=1
        po[a[i]]=1
print(c)