N = int(input())
A = sorted([int(input()) for i in range(N)])

if N % 2 == 0:
    print(2 * (sum(A[N // 2:]) - sum(A[:N // 2])) - (A[N // 2] - A[N // 2 - 1]))
else:
    print(2 * (sum(A[N // 2 + 1:]) - sum(A[:N // 2])) - min(A[N // 2] - A[N // 2 - 1], A[N // 2 + 1] - A[N // 2]))
