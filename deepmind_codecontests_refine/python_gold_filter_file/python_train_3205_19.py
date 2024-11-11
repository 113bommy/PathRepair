n,m = map(int, input().split())
h = list(map(int, input().split()))
t = [1 for i in range(n)]
for i in range(0,m):
    a,b = map(int, input().split())
    if h[a-1] >= h[b-1]:
        t[b-1] = 0
    if h[a-1] <= h[b-1]:
      t[a-1] = 0
print(sum(t))