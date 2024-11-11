import sys
sys.setrecursionlimit(1000000)
def input():
    return sys.stdin.readline()
n, m = [int(i) for i in input().split()]
e = [[] for _ in range(n)]
for _ in range(n - 1):
    a, b = [int(i) - 1 for i in input().split()]
    e[a].append(b)
    e[b].append(a)
dp1 = [0] * n


def dfs1(i=0, r=-1):
    s = 1
    for j in e[i]:
        if j != r:
            s *= dfs1(j, i)
            s %= m
    dp1[i] = s
    return s + 1


dfs1()
dp2 = [0] * n
dp2[0] = dp1[0]


def dfs2(i=0, r=-1, s=1):
    a = [1]
    for j in e[i]:
        if j != r:
            a.append(a[-1] * (dp1[j]+1) % m)
    b = [1]
    for j in reversed(e[i]):
        if j != r:
            b.append(b[-1] * (dp1[j]+1) % m)
    b.reverse()

    k = 0
    for j in e[i]:
        if j != r:
            l = (a[k] * b[k + 1] * s + 1)%m
            dp2[j] = l * dp1[j] % m
            dfs2(j, i, l)
            k += 1


dfs2()
print("\n".join(map(str,dp2)))
