a,b=map(int,input().split())
c,d=map(int,input().split())
e=int(input())
if abs(a-c)<=e*(b-d):
  print('YES')
else:
  print('NO')