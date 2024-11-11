n,m = map(int,input().split())
h = list(map(int,input().split()))
H = set(range(n))
for i in range(m):
    a,b = map(int,input().split())
    if h[a-1] <= h[b-1]:
        H.discard(a-1)
    if h[a-1] >= h[b-1]:
        H.discard(b-1)

print(len(H))