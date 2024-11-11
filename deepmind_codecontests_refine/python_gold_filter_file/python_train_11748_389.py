x,a,b=map(int,input().split())
if a>=b:
  print('delicious')
elif a+x+1<=b:
  print('dangerous')
else:
  print('safe')