from math import gcd

n, m, q = [int(s) for s in input().split()]
g = gcd(n, m)
n, m = map(lambda x: x // g, [n, m])
# print(n, m)

for _ in range(q):
    sx, sy, ex, ey = map(lambda x: x-1, [int(s) for s in input().split()])
    # print(sx, sy, ex, ey)

    if sy // [n, m][sx] == ey // [n, m][ex]:
        print("YES")
    else:
        print("NO")
