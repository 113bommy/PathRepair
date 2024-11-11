from collections import deque
H, W = map(int, input().split())
area = ['#']*(W+2)
for i in range(H):
    area += ['#']+list(input())+['#']
area += ['#']*(W+2)
H+=2
W+=2
move = [-1, 1, W, -W]
ans = 0
for i in range(H):
    for j in range(W):
        st = W*i+j
        if area[st]=='#': continue
        dq = deque([])
        dist = [-1]*(H*W)
        dq.append(st)
        dist[st] = 0
        while dq:
            now = dq.popleft()
            for dx in move:
                nxt = now+dx
                if dist[nxt]>=0 or area[nxt]=='#': continue
                dist[nxt] = dist[now]+1
                ans = max(ans, dist[nxt])
                dq.append(nxt)
print(ans)