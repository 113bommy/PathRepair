n,q=map(int,input().split())

A=list(map(int,input().split()))


C=[0]*n

for i in range(q):
    l,r=map(int,input().split())
    C[l-1]+=1
    if(r!=n):
        C[r]-=1


for i in range(1,n):
    C[i]+=C[i-1]

C.sort()
A.sort()

ans=0
for i in range(n):
    ans+=C[i]*A[i]
print(int(ans))
