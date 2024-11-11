import collections
import math

r, c, n, k = map(int, input().split())
T = []
ans  = 0
for i in range(n):
    x, y = map(int, input().split())
    T.append((x, y))
for ri in range (1, r + 1):
    for rj in range(ri, r + 1):
        for ci in range(1, c + 1):
            for cj in range(ci, c + 1):
                t = 0
                for i in range(len(T)):
                    if ri <= T[i][0] <= rj and ci <= T[i][1] <= cj:
                        t += 1
                if t >= k:
                    ans += 1
print(ans)