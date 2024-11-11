import bisect
from collections import defaultdict
n,m = map(int,input().split())
p = [list(map(int, input().split())) for _ in range(m)]
 
a = defaultdict(list)
for x,y in sorted(p):
    a[x].append(y)
for x,y in p:
    
    z=bisect.bisect(a[x],y)
    print("{0:06d}{1:06d}".format(x,z))