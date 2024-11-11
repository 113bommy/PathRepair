N, M, *A = map(int, open(0).read().split())
*A, = zip(*[iter(A)]*2)
A.sort()
cnt = 0
R = 0
for a, b in A:
    if R <= a:
        cnt += 1
        R = b
    elif b < R:
        R = b
print(cnt)
