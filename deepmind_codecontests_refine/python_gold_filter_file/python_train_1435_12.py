N, M = map(int, input().split())

e = [[] for _ in range(N)]
for i in range(M):
    a, b = map(int, input().split())
    e[a-1].append(b-1)
    e[b-1].append(a-1)
visited = [0]*N
visited[0] = 1
que = [0]
while que:
    x = que.pop(0)
    for i in e[x]:
        if visited[i] == 0:
            visited[i] = x+1
            que.append(i)

print("Yes")


print(*visited[1:], sep="\n")
