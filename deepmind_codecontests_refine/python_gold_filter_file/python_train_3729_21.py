
N, M = map(int, input().split())
X = [list(map(int, input().split())) for _ in range(M)]

res = [""] * M
ctr = [0] * (N + 1)
for i, (p, y) in sorted(enumerate(X), key=lambda x: (x[1][0], x[1][1])):
    ctr[p] += 1
    res[i] = "{:0>6}{:0>6}".format(p, ctr[p])

print(*res, sep="\n")
