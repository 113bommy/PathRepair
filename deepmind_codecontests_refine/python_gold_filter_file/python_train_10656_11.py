n = int(input())
l = 1000000000
r = 1
segs = []
for i in range(n):
    p = input().split()
    a, b = int(p[0]), int(p[1])
    if a < l:
        l = a
    if r < b:
        r = b
    segs.append((a, b))
v = -1
for i in range(len(segs)):
    if segs[i] == (l, r):
        v = i+1
print(v)