
n,p,q,r=input().split()
x=[]
x=list(map(int, input().split()))
p=int(p)
q=int(q)
r=int(r)

for i in range(int(n)):
    t=int(x[i])
    if i == 0:
        a = t * p
        b = a + t * q
        c = b + t * r
    else:
        if a < t * p:
            a = t * p
        if b < a + t * q:
            b = a + t * q
        if c < b + t * r:
            c = b + t * r

print(c)