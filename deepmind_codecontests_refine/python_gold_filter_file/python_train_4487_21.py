n = int(input())
a = sorted(map(int, input().split()))
ans = (a[n-1]-a[0])*(a[-1]-a[n])
for i in range(1, n):
    ans = min(ans, (a[n+i-1]-a[i])*(a[2*n-1]-a[0]))
print(ans)