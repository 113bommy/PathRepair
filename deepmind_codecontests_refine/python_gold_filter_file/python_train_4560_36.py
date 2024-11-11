N, K = map(int, input().split())
A = list(map(int, input().split()))
F = list(map(int, input().split()))
A.sort()
F.sort(reverse=True)
ok = 10**12
ng = -1

while ok-ng>1:
  X = (ok+ng)//2
  tmp = 0
  for i,e in enumerate(A):
    tmp += max(e-X//F[i],0)
  if tmp<=K:
    ok = X
  else:
    ng = X
print(ok)

    
  