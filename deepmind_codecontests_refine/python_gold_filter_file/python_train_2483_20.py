N,M = map(int, input().split())
x = [0]*N
for i in range(M):
  a,b = map(int, input().split())
  x[a-1] += 1
  x[b-1] += 1
for i in range(N):
  print(x[i])
