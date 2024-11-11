N=int(input())
A=list(map(int,input().split()))
ans=0
f=[1]*(N+1)
las=A[N]
g=[las]*(N+1)
flag=1
for i in range(0,N):
    f[i+1]=2*(f[i]-A[i])
for i in range(N,0,-1):
    g[i-1]=g[i]+A[i-1]
#print(f,g)
for i in range(N+1):
    if min(f[i],g[i])<=0:
        flag=0
        break
    ans=ans+min(f[i],g[i])
if g[N]>f[N]:
    flag=0
if flag==0:
    print(-1)
else:
    print(ans)