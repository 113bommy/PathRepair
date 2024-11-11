from collections import deque
import copy
H,W=map(int, input().split())
Ch,Cw=map(int, input().split())
Dh,Dw=map(int, input().split())
S=[list(str(input())) for i in range(H)]

field2=copy.deepcopy(S)
move=[[1,0],[-1,0],[0,1],[0,-1]]
ans=0
temp=deque()

def dfs2(x,y):
    field2[x][y]='#'
    temp.append([x,y])
    for i in range(4):
        nx=x+move[i][0]
        ny=y+move[i][1]
        if 0<=nx and nx<H and 0<=ny and ny<W and field2[nx][ny]=='.':
            dfs2(nx,ny)
    return temp

start=dfs2(Ch-1,Cw-1)

while True:
    if field2[Dh-1][Dw-1]=='#':
        print(ans)
        exit()
    else:
        for i in range(len(start)):
            ttemp=start.popleft()
            for hh in range(-2,3):
                for ww in range(-2,3):
                    nnx=ttemp[0]+hh
                    nny=ttemp[1]+ww
                    if 0<=nnx and nnx<H and 0<=nny and nny<W and field2[nnx][nny]=='.':
                        dfs2(nnx,nny)
        ans+=1
    if len(start)==0:
        print(-1)
        exit()
