n=int(input())
r=list(map(int,input().split()))
l=len(r)
a=[]
for i in range(0,l,1):
    if(i==0):
        a.append(r[i])
    else:
        a.append(r[i]+a[i-1])
a.insert(0,0)
a.insert(0,0)
p,q=list(map(int,input().split()))
print(a[q]-a[p])