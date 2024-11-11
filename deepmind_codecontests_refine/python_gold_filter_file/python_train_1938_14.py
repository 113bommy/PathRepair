r, d = map(int, input().split())
n = int(input())
ans = 0
for _ in range(n):
    a, b, c = map(int, input().split())
    if (a * a + b * b) ** 0.5 - c >= r - d and (a * a + b * b) ** 0.5 + c <= r:
        ans += 1
print(ans)
