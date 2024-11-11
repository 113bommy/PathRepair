import io
import os

from collections import Counter, defaultdict, deque



def findCycle(source, getNbr):  # via bfs for a undirected graph
    q = deque([source])
    dist = {source: 0}
    parent = {source: None}
    while q:
        node = q.popleft()
        d = dist[node]
        for nbr in getNbr(node):
            if nbr not in dist:
                q.append(nbr)
                dist[nbr] = d + 1
                parent[nbr] = node
            else:
                # If nbr is already assigned a dist, it can only one of [d-1, d, d+1]
                if dist[nbr] == d - 1:
                    assert nbr == parent[node]  # Ignore 2-cycles
                    continue
                assert dist[nbr] in [d, d + 1]
                # Follow backpointers until hit LCA of nbr and node to form cycle
                path1 = [nbr]
                path2 = [node]
                while path1[-1] != path2[-1]:
                    if dist[path1[-1]] >= dist[path2[-1]]:
                        path1.append(parent[path1[-1]])
                    else:
                        path2.append(parent[path2[-1]])
                assert path1[-1] == path2[-1]
                path2.pop()
                return path1 + path2[::-1]

    return None

def solveBrute(N, ):
    MOD = 10 ** 9 + 7

    from itertools import permutations
    count = 0
    for perm in permutations(range(N)):

        def getNbr(i):
            ret = []
            for j in reversed(range(i)):
                if perm[j] > perm[i]:
                    ret.append(j)
                    break

            for j in range(i + 1, N):
                if perm[j] > perm[i]:
                    ret.append(j)
                    break
            return ret
        works = False
        for i in reversed(range(N)):
            
            works = findCycle(i, getNbr)
            if works:
                break
        if works:
            #print(perm, works)
            count += 1

    return count


def solve(N, ):
    MOD = 10 ** 9 + 7
    fact = [1]
    for i in range(1, N + 1):
        fact.append((fact[-1] * i) % MOD)
    return (fact[N] - pow(2, N - 1, MOD)) % MOD

if False:
    for n in range(3, 20):
        print('N', n, solveBrute(n), solve(n))
        assert solveBrute(n) == solve(n)


if __name__ == "__main__":
    input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

    N, = [int(x) for x in input().split()]
    ans = solve(N, )
    print(ans)

