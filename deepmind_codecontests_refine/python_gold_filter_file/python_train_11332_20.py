n, m = map(int, input().split())
a = ['']*n
b = ['']*m
for i in range(n):
  a[i] = str(input())
for i in range(m):
  b[i] = str(input())
for i in range(n-m+2):
  c = a[i:i+m]
  for j in range(n-m+2):
    d = [e[j:j+m] for e in c]
    if b == d:
      print('Yes')
      exit()
else:
  print('No')