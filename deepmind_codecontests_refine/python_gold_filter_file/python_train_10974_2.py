n = int(input())
a = [[0] * n for i in range(n)]

k=0
for i in range(n):
  for j in range(n):
    a[i][j] = '.'
for i in range(n):
  for j in range(n):
    if (i % 2 == 1) and (j % 2 == 1):
      a[i][j]='C'
      k += 1
    if (i % 2 == 0) and (j % 2 == 0):
      a[i][j]='C'
      k += 1
print(k)
for i in range(n):
  for j in range(n):
     print(a[i][j], end='')
  print()