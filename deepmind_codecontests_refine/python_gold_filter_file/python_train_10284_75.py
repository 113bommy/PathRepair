k=int(input())
a,b=map(int,input().split())
x=b//k
if x*k>=a:
  print('OK')
else:
  print('NG')