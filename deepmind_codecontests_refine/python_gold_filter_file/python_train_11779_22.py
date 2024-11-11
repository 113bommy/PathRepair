a, b, c = [int(x) for x in input().split()]
d, e, f = [int(x) for x in input().split()]
d -= a
if d > 0:
    d, b = d - min(d, b), b - min(d, b)
if b > 0:
    e -= b
c -= max(0, d) + max(0, e) + max(0, f)

if d > -1 and e > -1 and c <= 0:
    print("YES")
else:
    print("NO")