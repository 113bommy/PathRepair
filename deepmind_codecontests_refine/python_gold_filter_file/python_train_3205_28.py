n,m = map(int,input().split())
h = list(map(int,input().split()))
p = [0 for i in range(n)]
for i in range(m):
    a,b = map(int,input().split())
    if h[a-1] >= h[b-1]:
        p[b-1] = -1
    if h[a-1] <= h[b-1]:
        p[a-1] = -1
print(p.count(0))