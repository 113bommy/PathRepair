N = int(input())
A = [list(map(int,input().split())) for _ in range(2)]

ma = 0
for i in range(N):
  ma = max(ma, sum(A[0][0:i+1])+sum(A[1][i:]))
print(ma)