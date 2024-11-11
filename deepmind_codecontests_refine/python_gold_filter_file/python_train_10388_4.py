import sys
from bisect import bisect_left
sys.setrecursionlimit(1000000)
INF = pow(10, 10)

changed = []
input = sys.stdin.readline
N = int(input())
A = [int(a) for a in input().split()]
Edge = [[] for _ in range(N)]
for _ in range(N-1):
    u, v = map(int, input().split())
    Edge[u-1].append(v-1)
    Edge[v-1].append(u-1)
LIS = [INF] * N

def dfs(i, pre, Ans):
    changeID = bisect_left(LIS, A[i])
    changed.append((changeID, LIS[changeID]))
    LIS[changeID] = min(A[i], LIS[changeID])
    #print(i, LIS)
    #print(changed)
    Ans[i] = bisect_left(LIS, INF) 
    for nextN in Edge[i]:
        if nextN != pre: dfs(nextN, i, Ans)
    backID, backV = changed.pop()
    LIS[backID] = backV
    return 0

def solve():
    Ans = [1] * N
    dfs(0, 0, Ans)
    print("\n".join(map(str, Ans)))
    
    return 0

if __name__ == "__main__":
    solve()