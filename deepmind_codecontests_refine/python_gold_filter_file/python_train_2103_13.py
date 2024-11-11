def polycarp(a,b,c,d,k):
    z = a/c
    y = b/d
    q = 0
    s = 0
    t = u = 0
    s = z - int(z)
    if s == 0:
        t = z
    else:
        t = int(z+1)
        
    q = y - int(y)
    if q == 0:
        s = y
    else:
        s = int(y+1)
    
    if t + s > k:
        print(-1)
    
    if t + s <= k:
        print(int(t) ,end = " ")
        print(int(s))

t = int(input())
for i in range(t):
    a,b,c,d,k = [int(i) for i in input().split()]
    ans = polycarp(a,b,c,d,k)
    ans