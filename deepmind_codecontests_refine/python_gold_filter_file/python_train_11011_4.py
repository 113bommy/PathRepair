n, k = map(int, input().split())
a = list(map(int, input().split()))
for i in range(k):
    acc = [0 for j in range(n+1)]
    for j in range(n):
        acc[max(0, j - a[j])] += 1
        acc[min(n-1, j + a[j]) + 1] -= 1
    for j in range(n):
        acc[j+1] += acc[j]
    a = acc[:-1]
    if sum(a) == n * n:

        break
print(" ".join(map(str, a)))
