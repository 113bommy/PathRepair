n, = map(int,input().split())
map(int,input().split())

p = [-1] * (n + 1)
m ,= map(int,input().split())
for i in range(m):
    a, b ,c = map(int,input().split())
    if(p[b] < 0):
        p[b] = c
    else :
        p[b] = min(p[b],c);
print (-1 if(p.count(-1) > 2) else sum(p) + 2)
