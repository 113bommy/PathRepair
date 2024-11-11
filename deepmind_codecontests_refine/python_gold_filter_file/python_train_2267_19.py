X,N = map(int,input().split())
*P, = map(int,input().split())

d = 200
ans = 0
for i in range(102):
    if i in P: continue
    if d > abs(X-i):
        d = abs(X-i)
        ans = i
print(ans)