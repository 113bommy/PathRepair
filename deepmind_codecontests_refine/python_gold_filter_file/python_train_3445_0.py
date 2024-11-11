n,m=map(int,input().split())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
ans=[[0]*m for i in range(n)]
l=0
z=0
p=0
for i in a:
    l=l^i
for j in b:
    p=p^j
for w in range(1,m):
    z=z^b[w]
if l!=p:
    print("NO")
else:
    print("YES")
    for i in range(1,m):
        ans[0][i]=b[i]
    for j in range(1,n):
        ans[j][0]=a[j]
    ans[0][0]=a[0]^z    
    for i in range(len(ans)):
        print(*ans[i])
    
            

