import sys
n=int(input())
if n==2:
  print(-1)
  sys.exit()
if n==3:
  print('aa.')
  print('..a')
  print('..a')
  sys.exit()

x=(n//4)-1
y=(n%4)+4

l=[[['a','a','b','c'],['d','d','b','c'],['b','c','a','a'],['b','c','d','d']],[['a','a','b','b','a'],['b','c','c','.','a'],['b','.','.','c','b'],['a','.','.','c','b'],['a','b','b','a','a']],[['a','a','b','c','.','.'],['d','d','b','c','.','.'],['.','.','a','a','b','c'],['.','.','d','d','b','c'],['b','c','.','.','a','a'],['b','c','.','.','d','d']],[['a','a','b','b','c','c','.'],['d','d','.','d','d','.','a'],['.','.','d','.','.','d','a'],['.','.','d','.','.','d','b'],['d','d','.','d','d','.','b'],['.','.','d','.','.','d','c'],['.','.','d','.','.','d','c']]]

if n<8:
  for i in range(n):
    print(''.join(l[n-4][i]))
  sys.exit()

ans=[]
for i in range(n):
  ans1=['.']*n
  ans.append(ans1)

for i in range(x):
  for j in range(4):
    for k in range(4):
      ans[i*4+j][i*4+k]=l[0][j][k]

for j in range(y):
  for k in range(y):
    ans[x*4+j][x*4+k]=l[y-4][j][k]

for i in range(n):
  print(''.join(ans[i]))