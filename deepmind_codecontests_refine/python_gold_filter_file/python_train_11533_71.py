from collections import deque

queue = deque()

H,W = [int(v) for v in input().split()]
ch,cw = [int(v) for v in input().split()]
dh,dw = [int(v) for v in input().split()]

S = [input() for _ in range(H)]
visited = [[-1 for _ in range (W)] for _ in range(H)]

queue.append((cw-1,ch-1,0))

def check(x,y):
    return x > -1 and x < W and y > -1 and y < H and S[y][x] != "#" and visited[y][x] == -1

while len(queue) != 0:
    x,y,c = queue.popleft()
    if visited[y][x] != -1:
        continue
    visited[y][x] = c

    for d in [1,-1]:
        if check(x+d,y):
            queue.appendleft([x+d,y,c])
        if check(x,y+d):
            queue.appendleft([x,y+d,c])
    
    for dx in [-2,-1,0,1,2]:
        for dy in [-2,-1,0,1,2]:
            if check(x+dx,y+dy):
                queue.append((x+dx,y+dy,c+1))

print(visited[dh-1][dw-1])
