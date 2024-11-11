n,m = list(map(int,input().split()))
l = list(map(int,input().split()))
l.sort()

d = {}

for i in range(1, 101):
    d[i] = 0

s = 0

for i in range(n):
    d[l[i]] += 1
    s = s + 1

pr = 0

for i in d:
    if d[i] != 0:
        pr += 1

smax = 0

for i in d:
    if d[i] > smax:
        smax = d[i]

if smax % m == 0:
    bl = smax // m
else:
    bl = smax // m + 1

print(max(bl*m*pr - s,0))
