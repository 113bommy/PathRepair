n, k = map(int, input().split())
gj = -10000000000
for i in range(n):
    f, t = map(int, input().split())
    if t > k:
        f = f-t+k
    if f > gj:
        gj = f
print(gj)
