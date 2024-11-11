n,k = map(int,input().split())
p=0
c=0
ans=-10000000001
for i in range(n):
    f,t = map(int,input().split())
    if t>k:
        s=f-(t-k)
    else:
        s=f
    ans = max(ans,s)
print(ans)