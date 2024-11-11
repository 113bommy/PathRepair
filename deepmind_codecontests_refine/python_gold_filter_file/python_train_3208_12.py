N = int(input())

Ls = set()
for i in range(1, N + 1):
    for j in range(i + 1, N + 1):
        Ls.add((i, j))

K = N - (N % 2)
for i in range(1, K // 2 + 1):
    Ls.remove((i, K - i + 1))

print(len(Ls))
for l in Ls:
    print("%d %d" % l)