n,*a=map(int,open(0).read().split())
a.sort()
s=1
for i in a:
    s *= i
    if s > 1e18:
        print(-1)
        exit()
print(s)