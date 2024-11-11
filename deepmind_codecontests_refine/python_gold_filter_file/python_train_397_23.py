from collections import deque
h,w,k = map(int,input().split())
A = []
ans = 10**10
for i in range(h):
    A.append(input())
    for j in range(w):
        if A[i][j] == 'S':
            start = (i,j)
d = [[10**10]*w for _ in range(h)]
d[start[0]][start[1]] = 0
que = deque([start])
dx = [0,-1,0,1]
dy = [-1,0,1,0]
while que:
    px,py = que.popleft()
    ans = min(ans, 2 + (min(px,py,h-px-1,w-py-1)-1)//k)
    for i in range(4):
        nx = px + dx[i]
        ny = py + dy[i]
        if 0 <= nx < h and 0 <= ny < w and A[nx][ny] == '.' and d[nx][ny] == 10**10:
            d[nx][ny] = d[px][py] + 1
            if d[nx][ny] <= k:
                que.append((nx,ny))
print(ans)
