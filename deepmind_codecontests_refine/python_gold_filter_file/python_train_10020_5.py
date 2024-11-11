import sys

readline = sys.stdin.readline

ns = lambda: readline().rstrip()
ni = lambda: int(readline().rstrip())
nm = lambda: map(int, readline().split())
nl = lambda: list(map(int, readline().split()))

def solve():
    n, k = nm()
    k -= 1
    G = [list() for _ in range(n)]
    for _ in range(n-1):
        u, v = nm()
        u -= 1; v -= 1
        G[u].append(v)
        G[v].append(u)

    # q = [k]
    # siz = [-1]*n
    # while q:
    #     v = q[-1]
    #     if siz[v] < 0:
    #         siz[v] = 0
    #         for x in G[v]:
    #             if siz[x] < 0:
    #                 q.append(x)
    #     else:
    #         q.pop()
    #         siz[v] = 1
    #         for x in G[v]:
    #             siz[v] += siz[x]

    if len(G[k]) <= 1:
        print('Ayush')
        return
    # print('Ayush' if sum(siz[x] & 1 for x in G[v]) & 1 else 'Ashish')
    print('Ayush' if (n+1) & 1 else 'Ashish')

    return

# solve()

T = int(input())
for _ in range(T):
    solve()
