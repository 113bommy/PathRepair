n=int(input())
if n%2!=0:
  print(0)
else:
  a=0
  for i in range(1,26):
    a+=(n//(2*5**i))
  print(a)