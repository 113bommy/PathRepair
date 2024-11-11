n = int(input())
a = [input() for i in range(n)] 

for i in range(1, n):
  if a[i-1][-1]!=a[i][0] or a[i] in a[:i-1]:
    print('No')
    break
else:
  print('Yes')