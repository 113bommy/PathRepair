n,m=map(int, input().split())
A=[list(map(int, input().split())) for _ in range (n)]
b=[int(input()) for _ in range (m)]
for _ in range (n):
 print(sum(A[_][i] * b[i] for i in range(m)))