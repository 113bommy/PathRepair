n = int(input())
a = list(tuple(map(int, input().split())) for i in range(n))
s = sum(t for t, w in a)
a = [(t / w, t, t + w) for t, w in a]
a.sort(reverse = True)
d, i = s, 0
while d >= 0:
    s -= a[i][1]
    d -= a[i][2]
    i += 1
i -= 1
s += a[i][1]
d += a[i][2]
if a[i][1] == 2:
    j = i + 1
    while j < n and a[j][1] == 2: j += 1
    if j < n and d >= a[j][2]:
        i = 0
        s -= 1
if i > 0: 
    i -= 1
    if a[i][1] == 1:
        d += a[i][2]
        j = i + 1
        while j < n and a[j][1] == 1: j += 1
        if j < n and d >= a[j][2]: s -= 1
print(s)