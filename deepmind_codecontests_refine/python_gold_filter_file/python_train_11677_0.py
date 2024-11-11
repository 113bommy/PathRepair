import sys,atexit
from io import BytesIO
inp = BytesIO(sys.stdin.buffer.read())
input = lambda:inp.readline().decode('ascii')
buf = BytesIO()
sys.stdout.write = lambda s: buf.write(s.encode('ascii'))
atexit.register(lambda:sys.__stdout__.buffer.write(buf.getvalue()))

n,m = map(int,input().split())
if m%2 == 0:
    steps = []
    for j in range(m//2):
        for i in range(n):
            steps.append((j,i))
            steps.append((m-j-1,n-i-1))
else:
    steps = []
    for j in range(m//2):
        for i in range(n):
            steps.append((j,i))
            steps.append((m-j-1,n-i-1))
    l = 0
    r = n-1
    mid = m//2
    while l<=r:
        steps.append((mid,l))
        if l != r:
            steps.append((mid,r))
        l += 1
        r -= 1

for x,y in steps:
    print(y+1,x+1)

#vis = set()
#for i in range(1,len(steps)):
#    dx,dy = steps[i][0]-steps[i-1][0],steps[i][1]-steps[i-1][1]
#    assert((dx,dy) not in vis)
#    vis.add((dx,dy))

#print(steps)
#C = [list('.'*m) for _ in range(n)]
#for i,e in enumerate(steps):
#    x,y = e
#    C[y][x] = chr(65+i)
#for c in C:
#    print(''.join(c))
