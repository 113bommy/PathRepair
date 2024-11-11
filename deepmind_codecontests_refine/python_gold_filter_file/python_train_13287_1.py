n,a,b=map(int,input().split())
ans=0
for i in range(1,n):
    x=n-i
    if a//x and b//i:
        ans=max(ans, min(a//x,b//i))
print(ans)