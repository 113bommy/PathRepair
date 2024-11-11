from collections import deque
n=int(input())
r1,c1=map(int,input().split())
r2,c2=map(int,input().split())
grid=[]
for i in range(n):
    grid.append(list(input()))

visited1=set()
quee1=deque()
quee1.append((r1-1,c1-1))
visited1.add((r1-1,c1-1))
while quee1:
    c,r=quee1.popleft()
    if r>0:
        if grid[c][r-1]=='0' and (c,r-1)not in visited1:
            quee1.append((c,r-1))
            visited1.add((c,r-1))
    if r<n-1:
        if grid[c][r+1]=='0' and (c,r+1)not in visited1:
            quee1.append((c,r+1))
            visited1.add((c,r+1))
    if c>0:
        if grid[c-1][r]=='0' and (c-1,r)not in visited1:
            quee1.append((c-1,r))
            visited1.add((c-1,r))
    if c<n-1:
        if grid[c+1][r]=='0' and (c+1,r)not in visited1:
            quee1.append((c+1,r))
            visited1.add((c+1,r))

visited2=set()
quee2=deque()
quee2.append((r2-1,c2-1))
visited2.add((r2-1,c2-1))
while quee2:
    c,r=quee2.popleft()
    if r>0:
        if grid[c][r-1]=='0' and (c,r-1)not in visited2:
            quee2.append((c,r-1))
            visited2.add((c,r-1))
    if r<n-1:
        if grid[c][r+1]=='0' and (c,r+1)not in visited2:
            quee2.append((c,r+1))
            visited2.add((c,r+1))
    if c>0:
        if grid[c-1][r]=='0' and (c-1,r)not in visited2:
            quee2.append((c-1,r))
            visited2.add((c-1,r))
    if c<n-1:
        if grid[c+1][r]=='0' and (c+1,r)not in visited2:
            quee2.append((c+1,r))
            visited2.add((c+1,r))
m=1000000000
for i in visited1:
    for j in visited2:
        x=(i[0]-j[0])**2+(i[1]-j[1])**2
        if x<m:
            m=x
print(m)
#print(grid)