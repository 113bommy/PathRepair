from math import sqrt
n, k = map(int, input().split())
if k > n*n:
  print(-1)
else:
  a = n*n - k
  a2 = int(sqrt(a))
  if a == a2**2:
    t = n - a2
    for _ in range(t):
      print('1 '*n)
    for _ in range(n-t):
      print('1 '*t + '0 '*(n-t))
  else:
    t = n - a2 - 1
    for _ in range(t):
      print('1 '*n)
    i = k - t*(2*n-t)
    i0 = i%2
    i1 = i//2
    if i0 == 1:
      print('1 '*(t+1+i1) + '0 '*(n-t-1-i1)) 
      for _ in range(i1):
        print('1 '*(t+1) + '0 '*(n-t-1))
      for _ in range(n-t-1-i1):
        print('1 '*t + '0 '*(n-t))
    else:
      print('1 '*(t+i1) + '0 '*(n-t-i1))
      if i1 == 1:
        print('1 '*t + '0 ' + '1 ' + '0 '*(n-t-2))
        for _ in range(n-t-2):
          print('1 '*t + '0 '*(n-t))
      else:
        print('1 '*(t+2) + '0 '*(n-t-2))
        for _ in range(i1-2):
          print('1 '*(t+1) + '0 '*(n-t-1))
        for _ in range(n-t-i1):
          print('1 '*t + '0 '*(n-t))
