n = int(input())
a = list(map(int,input().split()))
l,p,q = [],0,0
for i in a:
    if i == 0:
        p += 1
    else:
        t = int(i**0.5)
        s = i - t**2
        if s == 0:
            p += 1
            q += 1
        else:
            s = min(s,2*t+1-s)
            l.append(s)
if p > n//2:
    p -= n//2
    if q > p:
        print(p)
    else:
        print(2*p-q)
elif p == n//2:
    print(0)
else:
    l.sort()
    s = 0
    p = n//2-p
    for i in range(p):
        s += l[i]
    print(s)