import queue
dx=[1,0,-1,0]
dy=[0,1,0,-1]
H,W=map(int,input().split())
S=[]
for h in range(H):
  S.append(input())

def bfs(s):
  dist = [[-1]*W for _ in range(H)]
  
  h,w = s
  dist[h][w]=0
  que = queue.Queue()
  que.put(s)
  
  while not(que.empty()):
    h,w = que.get()
    for d in range(4):
      nh = h + dx[d]
      nw = w + dy[d]
      if nh<0 or H<=nh or nw<0 or W<=nw:
        continue
      if S[nh][nw]=="#":
        continue
      if dist[nh][nw]==-1:
        dist[nh][nw]=dist[h][w]+1
        que.put([nh,nw])
  return dist[h][w]

ans = 0
for h in range(H):
  for w in range(W):
    if S[h][w]==".":
      ans = max(ans,bfs([h,w]))
print(ans)
      
