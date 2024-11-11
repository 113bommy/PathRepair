n, k = map(int, input().split())
a = list(map(int, input().split()))
for _ in range(min(k, 50)):
    b = [0]*(n+1)
    for i in range(n):
        b[max(0, i-a[i])] += 1
        b[min(i+a[i]+1, n)] -= 1
    for i in range(1, n+1):
        b[i] += b[i-1]
    for i in range(n):
        a[i] = b[i]
print(*a)