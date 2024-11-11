def gcd(a,b):
    if b == 0: return a
    return gcd(b, a%b)

def lcm(a,b):
    return a//gcd(a,b)*b

t,w,b = map(int,input().split())
p = min(w,b)
lc = lcm(w,b)
kol = t//lc
ret = kol*p
zv = t%lc
ret += min(zv, p-1)
g = gcd(ret, t)
ret//=g
t//=g
print(ret,'/',t,sep="")
