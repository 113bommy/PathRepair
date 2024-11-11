import math

n = int(input())
ta = [tuple(map(int, input().split())) for _ in range(n)]

a, b = ta[0]
for i in range(n):
    x, y = ta[i]
    z = max(-(-a//x), -(-b//y))
    a = x * z
    b = y * z

ans = a + b
print(ans)