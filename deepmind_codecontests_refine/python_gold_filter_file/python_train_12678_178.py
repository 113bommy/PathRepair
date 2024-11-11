N, A, B = map(int, input().split())
n = A + B
print(A*(N//n) +min(N%n,A))