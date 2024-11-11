n = int(input())
t = 0
d1 = +30000000
d2 = -30000000
for i in range(n):
    k, d = map(int, input().split())
    if d == 2:
        d2 = max(d2, t)
    else:
        d1 = min(d1, t)
    t += k
if d1 <= d2:
    print("Impossible")
elif d2 == -30000000:
    print("Infinity")
else:
    print(1899 - d2 + t)