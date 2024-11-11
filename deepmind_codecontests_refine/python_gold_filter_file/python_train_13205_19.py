def ncr(n,r):
    g = 1
    for i in range(1,r+1):
        g*=(n-r+i)
        g//=i
    return g
n,a,b= map(int,input().split())
nv = sorted(list(map(int,input().split())),reverse=True)
print(sum(nv[:a])/a)
ndica = {}
ndicfull = {}
conti = 0
fnv=nv[0]
for i,temp in enumerate(nv):
    if i<a:ndica[temp] = ndica.get(temp,0) + 1
    ndicfull[temp] = ndicfull.get(temp,0) + 1
    if temp==fnv:conti=i+1
if fnv == nv[a-1]:
    subb = min(conti,b)
    g=0
    for t in range(a,subb+1):g+=ncr(conti,t)
    print(g)
else:
    if ndicfull[nv[a-1]]==1:print(1)
    else:print(ncr(ndicfull[nv[a-1]],ndica[nv[a-1]]))