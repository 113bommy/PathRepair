import math
t = int(input())
for i in range(t):
    a,b,c,d,k=map(int,input().split())
    m= math.ceil(a/c)
    n= math.ceil(b/d)
    if n + m > k:
        print(-1)
    else:
        print(m,n)
