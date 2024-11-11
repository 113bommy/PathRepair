n=int(input())
l=[0 for i in range(100)]
al=[int(i) for i in input().split()]
for i in range(n-1):
    l1,r=input().split()
    l1,r=int(l1),int(r)
    for i in range(l1,r):
        l[i]=1
l1=al[0]
r=al[1]
ans=0
for i in range(l1,r):
    if(l[i]==0):
        ans+=1
print(ans)