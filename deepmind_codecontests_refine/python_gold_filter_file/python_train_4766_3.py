a,b = map(int, input().split())
if 2*a <= b <= 4*a and b%2==0:
  print('Yes')
else:
  print('No')