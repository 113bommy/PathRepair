import sys
r = lambda: sys.stdin.readline()
n, m = map(int,r().split())
d=[]
d2=[]
ddd=[]
for a in range(1,m+1):
    d=d+[a]

for a in range(n):
    i, j = map(int,r().split())
    for b in range(i, j+1):
        d2=d2+[b]
d2=list(set(d2))

for a in range(len(d)):
    cc=0
    for b in range(len(d2)):
        if d[a]==d2[b]:
            cc=1
    if cc ==0:
        ddd = ddd + [d[a]]

print(len(ddd))
c2=""
for a in range(len(ddd)):
    if a== len(ddd):
        sys.stdout.write(str(ddd[a]))
    else:       
        sys.stdout.write(str(ddd[a])+" ")
