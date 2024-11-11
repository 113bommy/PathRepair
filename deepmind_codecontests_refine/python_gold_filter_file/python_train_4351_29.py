a=[list(map(int,input().split())) for i in range(3)]
n=int(input())
b=[int(input()) for i in range(n)]
flag =False
for i in range(3):
  if all(a[i][j] in b for j in range(3)):
    flag=True
  if all(a[j][i] in b for j in range(3)):
    flag=True
if all(a[j][j] in b for j in range(3)) or all(a[i][2-i] in b for i in range(3)) :
  flag=True
if(flag):
  print("Yes")
else:
  print("No")
       
