import sys

sys.setrecursionlimit(10**6)
def MI(): return map(int,sys.stdin.readline().rstrip().split())


N,M = MI()
Graph = [[] for _ in range(N+1)]
for i in range(M):
    a,b = MI()
    Graph[a].append(b)
    Graph[b].append(a)

# 二部グラフであれば、(色1で塗る頂点の個数)*(色-1で塗る頂点の個数)-M
# 二部グラフでなければ、N*(N-1)//2-M

colors = [0]*(N+1)


def dfs(v,color):  # 二部グラフ判定
    colors[v] = color
    for w in Graph[v]:
        if colors[w] == color:
            return False
        if colors[w] == 0 and not dfs(w,-color):
            return False
    return True


if dfs(1,1):
    red = colors.count(1)
    blue = colors.count(-1)
    print(red*blue-M)
else:
    print(N*(N-1)//2-M)
