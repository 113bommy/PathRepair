from collections import defaultdict

n = int(input())
a = [int(x) for x in input().split()]
b = [int(x) for x in input().split()]

#c = [(a[i] - b[i]) for i in range(0, n)]
c = [0] * n
d = defaultdict()
for i in range(0, n):
    c[i] = a[i] - b[i]
    if not (c[i] in d):
        d[c[i]] = 0
    if c[i] > 0:
        d[c[i]] += 1
    if c[i] < 0:
        c[i] = -c[i]
c.sort()
tot = 0
for i in range(0, n):
    if not(c[i] in d):
        continue
    if d[c[i]] > 0:
        tot += i
        d[c[i]] -= 1
print(tot)



