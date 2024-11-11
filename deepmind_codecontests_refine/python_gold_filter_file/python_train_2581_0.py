import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

import operator

N,H,W = map(int,readline().split())
m = map(int,read().split())
RCA = sorted(zip(m,m,m),key=operator.itemgetter(2),reverse=True)

root = list(range(H+W))
size = [1] * (H+W)
no_cycle = [True] * (H+W)

def find_root(x):
    y = root[x]
    if x == y:
        return y
    z = find_root(y)
    root[x] = z
    return z

def merge(x,y):
    x,y = find_root(x),find_root(y)
    sx,sy = size[x],size[y]
    if sx < sy:
        sx,sy = sy,sx
        x,y = y,x
    root[y] = x
    size[x] += sy
    no_cycle[x] = no_cycle[x] and no_cycle[y]

answer = 0
for R,C,A in RCA:
    x,y = R-1,H+C-1
    rx,ry = find_root(x),find_root(y)
    if rx == ry:
        if not no_cycle[rx]:
            continue
        no_cycle[rx] = False
    else:
        if (not no_cycle[rx]) and (not no_cycle[ry]):
            continue
        merge(rx,ry)
    answer += A

print(answer)
