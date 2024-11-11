import sys

sys.setrecursionlimit(10**6)

def dfs(G, v, cur):
    color[v] = cur;

    for next_v in G[v] :
        if not(color[next_v] == -1) :
            if color[next_v] == cur :
                return 0;
            continue;
        if not(dfs(G,next_v,1-cur)):
            return 0;
    return 1;

n,m = list(map(int,input().split()));

G = [[] for i in range(n)];
for i in range(m) :
    a,b = list(map(int,input().split()));
    G[a-1].append(b-1);
    G[b-1].append(a-1);

color = [-1]*n;

if dfs(G,0,0) :
    print(sum(color)*(n-sum(color))-m);
else :
    print(n*(n-1)//2-m);