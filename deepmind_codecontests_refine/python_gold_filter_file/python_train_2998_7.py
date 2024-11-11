import sys
sys.setrecursionlimit(1000000)

N = int(input())
G = [[] for i in range(N)]
for i in range(N-1):
    a,b = map(int,input().split())
    a,b = a-1,b-1
    G[a].append([b, i])

ans = [None]*(N-1)
def rec(cur, color):
    cnt = 1
    for (to, j) in G[cur]:
        if cnt == color:
            cnt += 1
        ans[j] = cnt
        rec(to, cnt)
        cnt += 1

rec(0,0)
print(max(ans))
[print(a) for a in ans]