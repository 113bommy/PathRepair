l=[list(map(int,input().split())) for i in range(3)]
x=l[0][0]
y=l[0][1]
z=l[0][2]
a=0
b=l[1][0]-x
c=l[2][0]-x
if b+y==l[1][1] and b+z==l[1][2] and c+y==l[2][1] and c+z==l[2][2]:
  print('Yes')
else:
  print('No')
  