n, k = map(int, input().split())
a = list(map(int, input().split()))
for _ in range(k):
    b = [0] * (n + 1)
    for i in range(n):
        b[max(0, i - a[i])] += 1
        b[min(n, i + a[i] + 1)] -= 1
    a[0] = b[0]
    for i in range(1, n):
        a[i] = b[i] + a[i - 1]
    if sum(a) == pow(n, 2):
        break
print(*a)