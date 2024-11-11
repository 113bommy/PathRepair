N = int(input())
A = sorted(int(input()) for _ in range(N))
if N % 2:
    B1 = A[:N // 2]
    C1 = A[N // 2:]
    c1 = 2 * sum(C1) - C1[0] - C1[1]
    b1 = 2 * sum(B1)
    B2 = A[:N // 2 + 1]
    C2 = A[N // 2 + 1:]
    c2 = 2 * sum(C2)
    b2 = 2 * sum(B2) - B2[-1] - B2[-2]
    print(max(c1 - b1, c2 - b2))
else:
    B = A[:N // 2]
    C = A[N // 2:]
    c = 2 * sum(C) - C[0]
    b = 2 * sum(B) - B[-1]
    print(c - b)
