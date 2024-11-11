import math
n = int(input())
step = math.ceil(n ** (1/2) )
k = n
i = 1
ans = []
while k > 0:
    tt = list(range(i, min(i + step, n + 1)))[::-1]
    ans += tt
    k -= step
    i += step
print(*ans)


