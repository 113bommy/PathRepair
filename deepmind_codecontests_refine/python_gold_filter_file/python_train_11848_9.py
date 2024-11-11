N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
m = 0
for i in range(N):
    p = min(A[i], B[i])
    B[i] -= p
    m += p
    q = min(A[i+1], B[i])
    A[i+1] -= q
    m += q
print(m)