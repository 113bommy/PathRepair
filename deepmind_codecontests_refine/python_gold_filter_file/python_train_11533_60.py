import sys
readline = sys.stdin.buffer.readline
def readstr():return readline().rstrip().decode()
def readints():return list(map(int,readline().split()))

from collections import deque

h,w = readints()

start = readints()
start = (start[0]-1)*w + start[1]-1

goal = readints()
goal = (goal[0]-1)*w + goal[1]-1

maze = [readstr() for i in range(h)]

dist = [10**10]*(h*w)

dq = deque()
dq.append(start)
dist[start] = 0

while dq:
    p = dq.popleft()
    y = p//w
    x = p%w
    for dy in range(-2,3):
        for dx in range(-2,3):
            if 0<=y+dy<h and 0<=x+dx<w and maze[y+dy][x+dx]=='.':
                q = (y+dy)*w + x+dx
                if abs(dy)+abs(dx)==1:
                    if dist[q]>dist[p]:
                        dq.appendleft(q)
                        dist[q] = dist[p]
                else:
                    if dist[q]>dist[p]+1:
                        dq.append(q)
                        dist[q] = dist[p] + 1

print(-1 if dist[goal]==10**10 else dist[goal])
