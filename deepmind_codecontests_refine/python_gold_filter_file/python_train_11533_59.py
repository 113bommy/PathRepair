from collections import deque

H,W = map(int,input().split())
C_h,C_w = map(lambda x:int(x)-1,input().split())
D_h,D_w = map(lambda x:int(x)-1,input().split())
S = [input() for _ in range(H)]

INF = int(1e10)
dist = [[INF]*(W) for _ in range(H)]
deq = deque()
deq.append((C_h,C_w,0))

move_a = [(1,0),(0,1),(-1,0),(0,-1)]
move_b = [(i,j)for i in range(-2,2+1) for j in range(-2,2+1) if abs(i)+abs(j)>=2]

while len(deq):
  h,w,c = deq.popleft()
  if dist[h][w] <= c:
    continue
  dist[h][w] = c
  for dh,dw in move_a:
    nh,nw = h+dh,w+dw
    if nh<0 or nw<0 or nh>=H or nw>=W:
      continue
    if S[nh][nw] == '#':
      continue
    if dist[nh][nw] > c:
      deq.appendleft((nh,nw,c))
  for dh,dw in move_b:
    nh,nw = h+dh,w+dw
    if nh<0 or nw<0 or nh>=H or nw>=W:
      continue
    if S[nh][nw] == '#':
      continue
    if dist[nh][nw] > c+1:
      deq.append((nh,nw,c+1))
  
print(dist[D_h][D_w] if dist[D_h][D_w]<INF else -1)