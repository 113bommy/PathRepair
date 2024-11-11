def e(x,y):
 A[y][x]='0'
 for d in range(-3,4):
  if 0<=x+d<8 and A[y][x+d]=='1':e(x+d,y)
  if 0<=y+d<8 and A[y+d][x]=='1':e(x,y+d)

for i in range(int(input())):
 print(f'Data {i+1}:')
 input()
 A=[list(input())for _ in[0]*8]
 e(int(input())-1,int(input())-1)
 for r in A:print(*r,sep='')
