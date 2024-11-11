from sys import exit


def dfs(node, letter):

    visited[node] = True
    ans[node-1] = letter
    s.add(tuple(sorted(graph[node]+[node])))

    for adj in graph[node]:
        if not visited[adj]:
            dfs(adj, letter)


n, m = map(int, input().split())
graph = [[] for _ in range(n+1)]
degree = [0]*(n+1)
visited = [False]*(n+1)
ans = ['x' for _ in range(n)]

for _ in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)
    degree[a] += 1
    degree[b] += 1

for node in range(1, n+1):
    if degree[node] == n-1:
        visited[node] = True
        ans[node-1] = 'b'

for letter in ['a', 'c']:
    for node in range(1, n+1):
        if not visited[node]:

            s = set()
            dfs(node, letter)

            if(len(s)) > 1:
                print("No")
                exit(0)

            break

print("Yes\n" + "".join(ans) if not False in visited[1:] else "No")
