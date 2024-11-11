import sys
sys.setrecursionlimit(10**9)

def solve():
    N = int(input())
    adjL = [[] for _ in range(N)]
    edges = []
    for _ in range(N-1):
        a, b = map(int, input().split())
        a, b = a-1, b-1
        adjL[a].append(b)
        adjL[b].append(a)
        if a > b:
            a, b = b, a
        edges.append((a, b))
    M = int(input())
    uvs = [tuple(map(lambda x: int(x)-1, input().split())) for _ in range(M)]

    def getPath(vSt, vEn):
        def dfs(vNow, vPar):
            if vNow == vEn:
                path.append(vNow)
                return True
            for v2 in adjL[vNow]:
                if v2 != vPar:
                    if dfs(v2, vNow):
                        path.append(vNow)
                        return True
        path = []
        dfs(vSt, -1)
        return path

    edgeConstraints = []
    for u, v in uvs:
        path = getPath(u, v)
        setEdge = set()
        for j in range(len(path)-1):
            a, b = path[j], path[j+1]
            if a > b:
                a, b = b, a
            setEdge.add((a, b))
        edge = 0
        for j, (a, b) in enumerate(edges):
            if (a, b) in setEdge:
                edge |= 1<<j
        edgeConstraints.append(edge)

    numEs = []
    for S in range(1<<M):
        edge = 0
        for i, edgeConstraint in enumerate(edgeConstraints):
            if (S>>i) & 1:
                edge |= edgeConstraint
        numE = bin(edge).count('1')
        numEs.append(numE)

    pow2s = [1]
    for i in range(N):
        pow2s.append(pow2s[-1]*2)

    ans = 0
    for S, numE in enumerate(numEs[1:], 1):
        num1 = bin(S).count('1')
        if num1 % 2:
            ans += pow2s[N-1-numE]
        else:
            ans -= pow2s[N-1-numE]

    print(pow2s[N-1] - ans)


solve()
