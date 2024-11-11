n =int(input())
w = list(input() for i in range(n))
if len(set(w))!=n:
  print('No')
else:
  if all(w[i][-1]==w[i+1][0] for i in range(n-1)):
    print('Yes')
  else:
    print('No')
  