import sys
read = sys.stdin.read


n, *ab = map(int, read().split())
ans = [0]*(n-1)
edges = [[]for _ in range(n)]
used = [0]*n

for i, a, b in zip(range(n-1), *[iter(ab)] * 2):
    edges[a-1].append([b-1, i])

for node in range(n):
    unable = used[node]
    color = 1

    for to, id in edges[node]:
        if color == unable:
            color += 1
        ans[id] = str(color)
        used[to] = color
        color += 1

print(max(used))
print('\n'.join(ans))