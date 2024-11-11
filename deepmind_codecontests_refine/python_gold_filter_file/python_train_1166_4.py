t = int(input())
sc = int(input())
v = int(input())
su = int(input())
c1 = int(input())
c2 = int(input())
c = 0

if c2 > c1:
    m = min(sc,v,su)
    c += (c2*m)

    su = su - m

    if su > 0:
        m = min(t,su)
        c += (c1*m)
else :
    m = min(t,su)
    c += (c1*m)

    su = su - m

    if su > 0:
        m = min(sc,v,su)
        c += (c2*m)

print(c)