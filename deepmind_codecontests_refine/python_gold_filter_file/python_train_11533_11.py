from collections import deque
inf = 10**10
dxdy = ((0,1),(0,-1),(1,0),(-1,0)) 
h, w = map(int, input().split())
ch, cw = map(int, input().split())
dh, dw = map(int, input().split())
s = ['#'*(w+2)] + ['#' + input() + '#' for _ in range(h)] + ['#'*(w+2)]
d = [[inf]*(w+1) for _ in range(h+1)]
d[ch][cw] = 0
q = deque([(ch,cw)])
while q: 
    y,x = q.pop() 
    for dx,dy in dxdy: 
        if s[y+dy][x+dx]=='.' and d[y+dy][x+dx] > d[y][x]:
            d[y+dy][x+dx] = d[y][x]
            q.append((y+dy,x+dx))
    for i in range(-2,3):
        for j in range(-2,3):
            if i==j==0:
                continue 
            elif 1<=y+i<=h and 1<=x+j<=w and s[y+i][x+j]=='.' and d[y+i][x+j]>d[y][x]+1:
                
                d[y+i][x+j] = d[y][x]+1
                q.appendleft((y+i,x+j)) 
ans = d[dh][dw] 
if ans == inf:
    print(-1)
else:
    print(ans)