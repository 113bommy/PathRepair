n, m = list(map(int, input().split()))
for k in range(1, n+1):
    a=input()
    s = a.count('*')
    if s == 2:
        x,y=[i+1 for i, t in enumerate(a) if t == "*"]
    else:
        if s == 1:
            b = a.index('*')+1
            d=k
if b == y:
    print(d,x)
else:
    print(d,y)