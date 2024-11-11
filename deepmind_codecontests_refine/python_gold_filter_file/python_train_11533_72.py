from collections import deque

H,W=map(int,input().split())
sy,sx=map(int,input().split())
gy,gx=map(int,input().split())
field=[list(input()) for _ in range(H)]
sy,sx,gy,gx=sy-1,sx-1,gy-1,gx-1

Walk=[[1,0],[0,1],[-1,0],[0,-1]]
Warp=[[i,j] for i in range(-2,3) for j in range(-2,3)] 

dist=[[-1]*W for _ in range(H)]
que=deque()
dist[sy][sx]=0
que.append([sy,sx])

while que:
    y,x=que.popleft()
    for walk in Walk:
        nx,ny=x+walk[0],y+walk[1]
        if nx<0 or nx>=W or ny<0 or ny>=H: continue
        if field[ny][nx]=="#": continue
        if dist[ny][nx]!=dist[y][x]:
            dist[ny][nx]=dist[y][x]
            que.appendleft([ny,nx])
    
    for warp in Warp:
        nx,ny=x+warp[0],y+warp[1]
        if nx<0 or nx>=W or ny<0 or ny>=H: continue
        if field[ny][nx]=="#": continue
        if dist[ny][nx]==-1:
            dist[ny][nx]=dist[y][x]+1
            que.append([ny,nx])

print(dist[gy][gx])
