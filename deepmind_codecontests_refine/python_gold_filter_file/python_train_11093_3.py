R = lambda: map(int, input().split())
n = int(input())
arr = list(R()) * 2
visited = [0] * (n + 1)

for ne in range(3, n + 1):
    if n % ne == 0 and not visited[ne]:
        g = n // ne
        if any(all(arr[i:i + g * (ne - 1) + 1:g]) for i in range(g)):
            print('YES')
            exit(0)
        i = ne
        while i < n + 1:
            visited[i] = 1
            i += ne
print('NO')