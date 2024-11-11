n, *A = map(int, open(0).read().split())
A = [0] + A + [0]
B = [abs(a1-a0) for a0, a1 in zip(A, A[1:])]
s = sum(B)
for i in range(1, n+1):
    print(s + abs(A[i-1]-A[i+1]) - B[i-1] - B[i])