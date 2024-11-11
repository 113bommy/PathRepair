n = int(input())
a = list(map(int, input().split()))

a = sorted(a, reverse=True)
ans = 0
for i in range(1, n):
    ans += a[i // 2]
print(ans)