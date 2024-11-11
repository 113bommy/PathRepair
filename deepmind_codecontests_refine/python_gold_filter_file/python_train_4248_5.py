N=int(input())
if N%2==0:
  n=N//2
  k=1
  c=0
  while 5**k <= n:
    c=c+n//5**k
    k=k+1
  print(c)
else:
  print(0)