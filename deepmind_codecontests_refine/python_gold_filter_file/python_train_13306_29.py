from math import log2

L = int(input())
n = int(log2(L))
print(n + 1, format(L, "b").count("1") - 1 + 2 * n)
Li = 1
for i in range(n):
    print(i + 1, i + 2, 0)
    print(i + 1, i + 2, Li)
    Li *= 2
mask = 2
for i in range(n):
    if L >> i & 1:
        print(i + 1, n + 1, L - (L & mask - 1))
    mask *= 2
