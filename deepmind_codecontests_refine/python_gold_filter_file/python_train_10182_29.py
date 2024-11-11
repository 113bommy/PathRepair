import sys
#input = sys.stdin.readline
from sys import setrecursionlimit
setrecursionlimit(10**9)

def inpl(): return list(map(int, input().split()))
N = int(input())
GA = inpl()
GB = inpl()

typ = [GA[i] <= GB[i] for i in range(3)]

if sum(typ) == 3:
    ans = 0
    for g in range(N//GA[0] + 1):
        D = N - GA[0]*g
        for s in range(D//GA[1] + 1):
            b, D2 = divmod(D - GA[1]*s, GA[2])
            ans = max(ans, D2 + g*GB[0] + s*GB[1] + b*GB[2])

elif sum(typ) == 2:
    ans = 0
    x, y = [i for i in range(3) if typ[i]]
    z = [i for i in range(3) if not typ[i]][0]
    for a in range(N//GA[x] + 1):
        b, D = divmod(N - GA[x]*a, GA[y])
        c, D2 = divmod(D + GB[x]*a + GB[y]*b, GB[z])
        ans = max(ans, D2 + c*GA[z])

elif sum(typ) == 1:
    ans = 0
    x, y = [i for i in range(3) if not typ[i]]
    z = [i for i in range(3) if typ[i]][0]
    c, D = divmod(N, GA[z])
    D += GB[z]*c

    for a in range(D//GB[x] + 1):
        b, D2 = divmod(D-GB[x]*a, GB[y])
        ans = max(ans, D2 + GA[x]*a + GA[y]*b)


else:
    ans = 0
    for g in range(N//GB[0] + 1):
        D = N - GB[0]*g
        for s in range(D//GB[1] + 1):
            b, D2 = divmod(D - GB[1]*s, GB[2])
            ans = max(ans, D2 + g*GA[0] + s*GA[1] + b*GA[2])

print(ans)