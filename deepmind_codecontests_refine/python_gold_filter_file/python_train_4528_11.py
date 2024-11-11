n = int(input())
a = [int(s) for s in input().split()]
a.sort()
c = 0
j = 0
for i in range(1, n):
    if a[i - 1] >= a[i]:
        c += (a[i - 1] - a[i]) + 1
        a[i] += (a[i - 1] - a[i]) + 1
print(c)
