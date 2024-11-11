def e(x,y):
 A[y][x]='0'
 for dx,dy in[[-3,0],[-2,0],[-1,0],[1,0],[2,0],[3,0],[0,-3],[0,-2],[0,-1],[0,1],[0,2],[0,3]]:
  if 0<=x+dx<8 and 0<=y+dy<8 and A[y+dy][x+dx]=='1':e(x+dx,y+dy)

for i in range(int(input())):
 print(f'Data {i+1}:')
 input()
 A=[list(input())for _ in[0]*8]
 e(int(input())-1,int(input())-1)
 for r in A:print(*r,sep='')
