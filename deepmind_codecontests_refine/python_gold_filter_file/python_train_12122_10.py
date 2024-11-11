n,m=map(int, input().split())
d=list(map(int, input().split()))
ans=[0]*(n+1)
for i in range(m) : 
    x=d[i]
    for j in range(x, n+1):
        if ans[j]==0:
            ans[j]=x
        else:
            break;
print(*ans[1:n+1])