c, v0, v1, a, l = [int(j) for j in input().split()]
for i in range(1, 1000000):
    c -= v0
    if i > 1:
        c += l
    if c <= 0:
        print(i)
        break
    v0 += a
    v0 = min(v0, v1)
