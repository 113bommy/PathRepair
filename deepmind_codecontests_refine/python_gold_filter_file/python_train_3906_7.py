n , m = map(int,input().split())
ans=m
for i in range(n):
    a , b = map(int,input().split())
    ans = max(ans,a+b)
print(ans)  