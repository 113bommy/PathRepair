import sys

A = list(map(int, sys.stdin.read().rstrip().split("\n")))
n = A[0]
del A[0]

#shellSort
cnt = 0

G = [i for i in [262913, 65921, 16577, 4193, 1073, 281, 77, 23, 8, 1] if i <= n]

m = len(G)

for i in range(m):
    g = G[i]
    # insertionSort
    for j in range(g, n):
        v = A[j]
        k = j - g
        while (k >= 0) and (A[k] > v):
            A[k + g] = A[k]
            k -= g
            cnt += 1
        A[k + g] = v

print(m)
print(*G)
print(cnt)
print("\n".join(map(str, A)))