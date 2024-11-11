n, m = map(int, input().split())
diff = []
total = 0
for i in range(n):
    a, b = map(int, input().split())
    diff.append(a - b)
    total += b

if total > m:
    print(-1)
else:
    diff.sort()
    i = 0
    n_compressed = n
    while i < n and total + diff[i] <= m:
        total += diff[i]
        i += 1
        n_compressed -= 1
    print(n_compressed)
