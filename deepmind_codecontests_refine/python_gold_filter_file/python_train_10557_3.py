n, k = map(int, input().split())
A = [i for i in range(2*n, 0, -1)]
for i in range(k):
    if i > n:
        i %= n
    A[2*i], A[2*i + 1] = A[2*i + 1], A[2*i]
print(' '.join(map(str, A)))