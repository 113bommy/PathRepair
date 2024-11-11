import io
import os

#input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

def solve():
    n, m = map(int, input().split())
    
    vals = []
    for _ in range(n):
        vals.append(list(map(int, input())))
        
    ops = []
    def flip(x1, y1, x2, y2, x3, y3):
        for a, b in ([x1, y1], [x2, y2], [x3, y3]):
            vals[b][a] = 1 - vals[b][a]
        ops.append((y1+1, x1+1, y2+1, x2+1, y3+1, x3+1))
        
    for y in range(n-2):
        for x in range(m):
            if x == m-1:
                if vals[y][x]:
                    flip(x, y, x, y+1, x-1, y+1)
            else:
                if vals[y][x]:
                    flip(x, y, x, y+1, x+1, y+1)
    for x in range(m-2):
        if vals[n-2][x]:
            flip(x, n-2, x+1, n-2, x+1, n-1)
        if vals[n-1][x]:
            flip(x, n-1, x+1, n-2, x+1, n-1)
            
    # a b
    # c d
    
    a = m-2, n-2
    b = m-1, n-2
    c = m-2, n-1
    d = m-1, n-1
    def last():
        return [vals[y][x] for x, y in [a, b, c, d]]
        
    if sum(last()) == 4:
        flip(*a, *b, *c)
    if sum(last()) == 1:
        i = last().index(1)
        if i == 0:
            flip(*a, *b, *c)
        elif i == 1:
            flip(*b, *d, *c)
        elif i == 2:
            flip(*a, *c, *d)
        else:
            flip(*b, *d, *c)
    if sum(last()) == 2:
        if last() == [1, 1, 0, 0]:
            flip(*a, *c, *d)
        elif last() == [1, 0, 1, 0]:
            flip(*a, *b, *d)
        elif last() == [1, 0, 0, 1]:
            flip(*a, *b, *c)
        elif last() == [0, 1, 1, 0]:
            flip(*a, *b, *d)
        elif last() == [0, 1, 0, 1]:
            flip(*a, *b, *c)
        else:
            flip(*a, *b, *c)
    if sum(last()) == 3:
        i = last().index(0)
        if i == 0:
            flip(*b, *c, *d)
        elif i == 1:
            flip(*a, *c, *d)
        elif i == 2:
            flip(*a, *b, *d)
        else:
            flip(*a, *b, *c)
            
    for row in vals:
        assert(not any(row))
    
    print(len(ops))
    for op in ops:
        print(*op)
    
t = int(input())

for _ in range(t):
    solve()
