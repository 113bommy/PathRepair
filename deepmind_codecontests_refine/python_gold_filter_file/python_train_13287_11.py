n, a, b = [int(x) for x in input().strip().split()]
ans = -1
for i in range(1, n):
    ans = max(ans, min(float('inf') if n-i == 0 else a//(n-i), float('inf') if i == 0 else b//i))
print(ans)
