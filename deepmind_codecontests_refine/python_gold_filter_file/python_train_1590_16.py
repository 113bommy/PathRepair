import math
for _ in range(1):
    n=int(input())
    l=list(map(int,input().split()))
    l.sort()
    s=0
    s2=0
    a=math.ceil(l[-1]**(1/(n-1)))
    b=math.floor(l[-1]**(1/(n-1)))
    for i in range(n):
        s=s+abs(l[i]-a**i)
        s2=s2+abs(l[i]-b**i)
    print(min(s,s2))
        