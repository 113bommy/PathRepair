n,m = map(int,input().split())
p = []
for i in range(n,int((n-1)/2),-1):
    if i % m == 0:
        p.append(i)
if len(p) != 0:
    print(min(p))
else:
    print(-1)