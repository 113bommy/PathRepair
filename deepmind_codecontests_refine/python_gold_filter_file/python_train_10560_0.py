n, m = [int(i) for i in input().split()]
p = list(map(int, input().split()))
s = [input().split() for _ in range(m)]
ps, result = sorted(p), [-1] * n
for i in range(n):
    if i % 2 == 0:
        c = 1
    else:
        c = 0
    result[p.index(ps[i])] = c
print(*result)
