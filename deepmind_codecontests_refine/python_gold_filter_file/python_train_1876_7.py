def dfs(r, c):
    global color, G
    S = [r]
    color[r] = c
    while (0 < len(S)):
        u = S.pop()
        for u in G[u]:
            v = color[u]
            if (v == None):
                color[u] = c
                S.append(u)
 
def assignColor():
    global color, G, n
    c = 1
    for i in range(n):
        if (color[i] == None):
            dfs(i, c)
            c += 1
 
n, m = list(map(int, input().split()))
 
G = [[] for i in range(n)]
for i in range(m):
    s, t = list(map(int, input().split()))
    G[s].append(t)
    G[t].append(s)
 
color = [None for i in range(n)]
 
assignColor()
 
q = int(input())

for i in range(q):
    s, t = list(map(int, input().split()))
    if (color[s] == color[t]):
        print("yes")
    else:
        print("no")