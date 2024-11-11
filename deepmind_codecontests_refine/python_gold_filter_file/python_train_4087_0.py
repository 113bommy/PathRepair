import sys
ints = (int(x) for x in sys.stdin.read().split())
sys.setrecursionlimit(3000)

N = 5*10**5
ans = [[] for i in range(N)]
aux = [-1]*N
G = [[] for i in range(N)]
tgt = [0 for i in range(N)]


def solve(n,G,tgt):
    for i in range(n):
        k = tgt[i]
        for j in G[i]:
            aux[tgt[j]] = i
        if aux[k]==i or len(G[i])<k or any(aux[t]!=i for t in range(k)):
            yield -1
            return
        ans[k].append(i)
    for t in range(n):
        for i in ans[t]:
            yield i+1
    return

def main():
    n, m = (next(ints) for i in range(2))
    for _ in range(m):
        i = next(ints)-1
        j = next(ints)-1
        G[i].append(j)
        G[j].append(i)
    for i in range(n):
        tgt[i] = next(ints)-1
    print(*solve(n,G,tgt))
    return

main()
