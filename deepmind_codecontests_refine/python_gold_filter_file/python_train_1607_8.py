readints = lambda: map(int, input().split(' '))
 
 
a,b,c=readints()
x,y,z=readints()
 
if a!=x and b!=y and c!=z:
  print('NO')
else:
  print('YES')