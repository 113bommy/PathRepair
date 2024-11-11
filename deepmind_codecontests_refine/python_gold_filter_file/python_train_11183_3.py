n = int(input())
a = [int(x) for x in input().split()]
t = int(input())
res = 1
a.sort()
for i in range(n):
    for j in range(i + 1, n):
        if a[j] - a[i] <= t:
            res = max(j - i + 1, res)
print(res)
