X, Y, Z, K = map(int, input().split())

A = list(map(int, input().split()))
B = list(map(int, input().split()))
C = list(map(int, input().split()))

N = []
for a in A:
    for b in B:
        N.append(a + b)
N.sort(reverse=True)
N = N[:K]

M = []
for n in N:
    for c in C:
        M.append(n + c)
M.sort(reverse=True)
M = M[:K]

print(*M, sep="\n")
