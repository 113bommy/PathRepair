def gcd(a,b):
    if b==0:
        return a
    else:
        return gcd(b, a%b)
    
n, m ,q = list(map(int, input().split()))
h = gcd(n,m)
nh = n//h
mh = m//h
for i in range(q):
    sx, sy, ex, ey = list(map(int, input().split()))
    if sx == 1:
        sind = (sy-1 + nh)//nh
    else:
        sind = (sy-1 + mh)//mh
    if ex == 1:
        eind = (ey-1 + nh)//nh
    else:
        eind = (ey-1 + mh)//mh
    if sind ==eind:
        print("YES")
    else:
        print("NO")
        