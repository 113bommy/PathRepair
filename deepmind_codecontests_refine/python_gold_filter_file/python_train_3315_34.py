a,b=map(int,input().split())
if (a+b)%3 and a%3 and b%3:
  print('Impossible')
else:
  print('Possible')