n, k = map(int, input().split())
A = list(map(int, input().split()))
for i in range(k):
    B = [0] * (n+1)
    for j in range(n):
        B[max(0, j-A[j])] += 1
        B[min(n, j+A[j]+1)] -= 1
    A[0] = B[0]
    for j in range(1, n):
        A[j] = A[j-1]+B[j]
    if A == [n]*n:
        print(*A)
        exit()
print(*A)
    