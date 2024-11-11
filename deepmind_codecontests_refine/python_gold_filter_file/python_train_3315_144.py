a,b=map(int,input().split())
if a%3!=0 and b%3!=0 and (a+b)%3!=0:
  print('Impossible')
else:
  print('Possible')
