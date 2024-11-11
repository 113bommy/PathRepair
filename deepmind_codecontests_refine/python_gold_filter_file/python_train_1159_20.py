n = int(input())
a = list(map(int, input().split()))
a.sort()
b = []
c = []
if len(a) >= 2:
    b.append(a[0])
    c.append(a[1])
else:
    b = a
i = 3
while i < len(a):
    if max(a[i] - b[len(b)-1], a[i-1]-c[len(c)-1]) < max(a[i-1] - b[len(b)-1], a[i]-c[len(c)-1]):
        b.append(a[i])
        c.append(a[i-1])
    else:
        b.append(a[i-1])
        c.append(a[i])
    i += 2
if i - 1 < len(a):
    if a[i-1] - b[len(b)-1] < a[i-1]-c[len(c)-1]:
        b.append(a[i-1])
    else:
        c.append(a[i-1])
c.reverse()
b = b + c
print(" ".join(str(i) for i in b))
