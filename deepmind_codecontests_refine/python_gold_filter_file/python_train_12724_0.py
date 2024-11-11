import sys
n = int(input())
c = {}
for i in [int(i) for i in input().split()]:
    c[i] = c.get(i, 0) + 1
maxi = max(c)
l = sorted(c)
for u in l[:-1]:
    if u + 1 not in c:
        print("NO")
        sys.exit()
    c[u + 1] -= c[u]
    if 0 > c[u + 1]:
        print("NO")
        sys.exit()
arr = list(c.values())
if arr.count(0) == 1 and c[maxi] == 0:
    print("YES")
else:
    print("NO")

