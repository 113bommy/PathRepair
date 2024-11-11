N,P = map(int,input().split())
i = round(P**(1/N))
res = []
if N == 1:
  print(P)
elif P == 1:
  print(1)
else:
  for i in range(i,0,-1):
    if P%i**N==0:
      print(i)
      break