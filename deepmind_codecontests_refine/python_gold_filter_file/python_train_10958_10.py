t=int(input())
for _ in range(t):
  #0 1 2
  x1, y1, z1=map(int, input().split())
  x2, y2, z2=map(int, input().split())
  res = 0
  #pair 2 of a with 1s of b
  m=min(z1, y2)
  res += 2*m
  z1-=m
  y2-=m
  neg=0
  #pair 1 of a with 1s of b
  m=min(y2, y1)
  y1-=m
  y2-=m
  if y1!=0: #1 is not over for a
    #pair remaining 1 of a with with 0s of b
    m=min(y1, x2)
    y1-=m
    x2-=m
    if y1!=0:
      #forced to pair 1 with 2s of b
      neg=2*y1
    #otherwise y1 is 0 then only 0 pairing left
    #no loss
  print(res-neg)
