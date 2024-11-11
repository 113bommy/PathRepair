import sys,io,os
from atexit import register
input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
sys.stdout = io.BytesIO()
register(lambda :os.write(1,sys.stdout.getvalue()))
def print(args=[], sep=' ', end='\n', file=sys.stdout):
    first = True
    sep = sep.encode()
    for a in args:
        if first: first = False
        else: file.write(sep)
        file.write(str(a).encode())
    file.write(end.encode())

visited = [[0]*1010 for _ in range(1010)]
out = [[-1]*1010 for _ in range(1010)]

cells = []
def dfs(x,y):
    global c
    Q = [(x,y)]
    while Q:
        x,y = Q.pop()
        if x >= n or x < 0 or y >= m or y < 0:
            continue
        if l[x][y] == b'*'[0]:
            c += 1
            continue
        if visited[x][y] :
            continue
        visited[x][y] = 1
        cells.append((x,y))
        Q.append((x+1,y))
        Q.append((x,y+1))
        Q.append((x-1,y))
        Q.append((x,y-1))

n , m , k = [int(x) for x in input().split()]
l = [input() for _ in range(n)]
for i in range(n):
    for j in range(m):
        if not visited[i][j] and l[i][j] == b'.'[0]:
            c = 0
            dfs(i,j)
            while cells:
                x = cells.pop()
                if visited[x[0]][x[1]] and out[x[0]][x[1]] == -1:
                    out[x[0]][x[1]] = c
ANS = []
for i in range(k):
    x , y = [int(x) for x in input().split()]
    ANS.append(out[x-1][y-1])
print(ANS,sep='\n')