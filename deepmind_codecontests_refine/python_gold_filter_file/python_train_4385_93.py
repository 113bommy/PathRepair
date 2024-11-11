x, y, z, t1, t2, t3 = list(map(int, input().split()))
d = abs(z-x)+abs(x-y)
a = 3*t3+d*t2
b = abs(x-y)*t1
if a<=b:
  print('YES')
else:
  print('NO')