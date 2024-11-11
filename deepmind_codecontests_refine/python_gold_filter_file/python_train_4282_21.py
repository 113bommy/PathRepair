import math
n, s = map(int, input().split())
v = list(map(int, input().split()))
least = min(v)
if sum(v) < s:
    print(-1)
else:
    for i in v:
        s -= (i-least)
    if s > 0:
        least -= ((s+n-1)/n)
    print(math.ceil(least))
