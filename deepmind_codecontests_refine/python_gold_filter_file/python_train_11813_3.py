a,b=map(int,input().split())
ans=[[0]*b for i in " "*a]
z=[list(map(int,input().split())) for _ in " "*a]
_z=[[z[j][i] for j in range(a)] for i in range(b)]
ok=0
for i in range(a):
    for j in range(b):
        if z[i][j]==1:
            ok+=1
            if sum(z[i])==b and sum(_z[j])==a:ans[i][j]=1
            elif sum(z[i])!=b and sum(_z[j])!=a:exit(print("NO"))
k=sum(sum(ans[i]) for i in range(a))
if k==0 and ok:exit(print("NO"))
print("YES")
for i in ans:print(*i)