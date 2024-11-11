import bisect
from itertools import*
n,m,k,*x=[int(v)for l in open(0) for v in l.split()];a=accumulate([0]+x[:n]);b=[*accumulate(x[n:])];print(max(i+bisect.bisect(b,k-v)for i,v in enumerate(a)if v<=k))