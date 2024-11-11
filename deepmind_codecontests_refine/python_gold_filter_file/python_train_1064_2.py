# Why do we fall? So we can learn to pick ourselves up.

n = int(input())
edges = [[] for i in range(0,n)]
for i in range(0,n-1):
    u,v = map(int,input().split())
    edges[u-1].append((v-1,i))
    edges[v-1].append((u-1,i))
ans = [-1]*(n-1)
cc = 0
for i in range(0,n):
    if len(edges[i]) == 1 and ans[edges[i][0][1]] == -1:
        ans[edges[i][0][1]] = cc
        cc += 1
for i in range(0,n-1):
    if ans[i] == -1:
        ans[i] = cc
        cc += 1
for i in ans:
    print(i)
