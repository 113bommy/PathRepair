n = int(input())
sx = sy = sz = 0
for i in range(n):
  x, y, z = (int(i) for i in input().split())
  sx += x
  sy += y
  sz += z
if sx == sy == sz == 0:
  print('YES')
else:
  print('NO')