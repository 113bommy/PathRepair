N = int(input())
A = [int(a) for a in input().split()]
B = [int(a) for a in input().split()]
if N > 10000:
    A = A[5050:] + A[:5050]
    B = B[5050:] + B[:5050]
ans = -1

D = [0] * N
L = [i-1 for i in range(N)]
R = [i+1 for i in range(N)]

def calc():
    i = 0
    c = 0
    ans = 0
    while c < N:
        while i < N:
            if B[i] == A[i]:
                if D[i] == 0:
                    c += 1
                    D[i] = 1
                if L[i] >= 0: R[L[i]] = R[i]
                if R[i] < N: L[R[i]] = L[i]
            if B[i] > A[i] and B[i] >= max(B[i-1], B[(i+1)%N]):
                k = - (-(B[i] - max(B[i-1], B[(i+1)%N], A[i])) // (B[i-1] + B[(i+1)%N]))
                B[i] -= (B[i-1] + B[(i+1)%N]) * k
                ans += k
                if k <= 0:
                    return -1
            i = R[i]
        i = N-1
        while i >= 0:
            if B[i] == A[i]:
                if D[i] == 0:
                    c += 1
                    D[i] = 1
                if L[i] >= 0: R[L[i]] = R[i]
                if R[i] < N: L[R[i]] = L[i]
            if B[i] > A[i] and B[i] >= max(B[i-1], B[(i+1)%N]):
                k = - (-(B[i] - max(B[i-1], B[(i+1)%N], A[i])) // (B[i-1] + B[(i+1)%N]))
                B[i] -= (B[i-1] + B[(i+1)%N]) * k
                ans += k
                if k <= 0:
                    return -1
            i = L[i]
    return ans

print(calc())