N, *A = map(int, open(0).read().split())
A.sort()
t, acc = 0, 0
for i in range(N - 1):
    acc += A[i]
    if 2 * acc < A[i + 1]:
        t = i + 1
print(N - t)