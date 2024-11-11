def f(n,s,x):
  if n == s == 0:
    return 1
  elif n == 0 or x == 0:
    return 0
  else:
    a = 0
    for i in range(x):
      a += f(n-1,s-i,i)
    return a
while True:
  n,s = map(int,input().split())
  if n == s == 0:
    break
  print(f(n,s,10))