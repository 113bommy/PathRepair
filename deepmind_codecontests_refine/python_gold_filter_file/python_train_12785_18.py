N = int(input())
P = [list(map(int, input().split())) for _ in range(N)]

P = sorted(P, key=lambda p: - p[0] - p[1])

ret = 0

for i, p in enumerate(P):
    if i % 2 == 0:
        ret += p[0]
    else:
        ret -= p[1]

print(ret)
