N = int(input())
A = tuple(map(int, input().split()))
B = tuple(map(int, input().split()))

def calc(A, B, N):
    M = N
    if len([i for i, (a, b) in enumerate(zip(A, B)) if a < b]) == 1:
        i = [i for i, (a, b) in enumerate(zip(A, B)) if a < b][0]

        for k in range(N // A[i] + 1):
            D = N - k * A[i]
            if D < 0:
                continue

            D += k * B[i]
            M = max(M, D)
    elif len([i for i, (a, b) in enumerate(zip(A, B)) if a < b]) == 2:
        i, j = [i for i, (a, b) in enumerate(zip(A, B)) if a < b]

        for k in range(N // A[i] + 1):
            D = N - k * A[i]
            l, D = divmod(D, A[j])

            D += k * B[i]
            D += l * B[j]

            M = max(M, D)
    elif len([i for i, (a, b) in enumerate(zip(A, B)) if a < b]) == 3:
        for g in range(N // A[0] + 1):
            for s in range(N // A[1] + 1):
                D = N - g * A[0] - s * A[1]

                if D < 0:
                    break

                q, r = divmod(D, A[2])

                D += g * B[0]
                D += s * B[1]

                r += g * B[0]
                r += s * B[1]
                r += q * B[2]

                M = max(M, D, r)
    return M

print(calc(B, A, calc(A, B, N)))
