import math


t = int(input())
for _ in range(t):
    n = int(input())
    ans = 0
    for i in range(n):
        ans += math.cos(math.radians(180 / n * i - 90))
    print(ans)