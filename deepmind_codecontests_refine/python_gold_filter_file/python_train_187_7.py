N=int(input())
F=[]
for i in range(N):    
    F.append(list(map(int,input().split())))
P=[]
for i in range(N):
    P.append(list(map(int,input().split())))

ans=-10**10
for k in range(1,1<<10):
    op=[k>>j&1 for j in range(10)]
    res=0
    for i in range(N):
        c=sum([F[i][j]&op[j] for j in range(10)])
        res+=P[i][c]
    ans=max(ans,res)

print(ans)