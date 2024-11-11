n=int(input())
cs=[list(map(int,input().split())) for _ in range(n-1)]
for i in range(n-1):
    t=0
    for c,s,f in cs[i:]:
        t=max(t,s)
        if t%f:
            t+=-t%f
        t+=c
    print(t)
print(0)