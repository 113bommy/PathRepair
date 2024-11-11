n, k = map(int, input().split())
a = list(map(int, input().split()))

for i in range(min(41, k)):
    t = [0] * (n+1)
    for j in range(n):
        t[max(0, j-a[j])] += 1
        t[min(j+a[j]+1, n)] -= 1

    for j in range(1, n):
        t[j] += t[j-1]
    a = t[:n]

print(*a)