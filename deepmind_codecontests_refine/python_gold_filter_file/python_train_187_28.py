N = int(input())
F = [ list(map(int, input().split())) for _ in range(N)]
P = [ list(map(int, input().split())) for _ in range(N)]

res = -(1<<30)

for b in range(1,1<<10):
  cc = 0
  for i in range(N):
    c = 0
    for j in range(10):
      if (b>>j&1) & F[i][j]:
        c+=1
    cc += P[i][c]
  if res<cc:
    res = cc
    
print(res)
