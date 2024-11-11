n = int(input())
a = list(map(int, input().split()))

max_node = [0 for _ in range(n+1)]
for i in range(n-1, -1, -1):
    max_node[i] = max_node[i+1] + a[i+1]

ans = 1
node = 1
for i in range(n+1):
    node -= a[i]
    if (i < n and node <= 0) or node < 0:
        print(-1)
        exit(0)
    node = min(node * 2, max_node[i])
    ans += node
print(ans)