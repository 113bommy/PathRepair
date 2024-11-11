from itertools import*;d={};g=d.get
for t in open(0).read().split():d[t[0]]=g(t[0],0)+1
print(sum(g(p,0)*g(q,0)*g(r,0)for p,q,r in combinations('MARCH',3)))