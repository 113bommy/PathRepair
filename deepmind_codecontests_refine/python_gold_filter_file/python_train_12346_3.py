import operator
import itertools
import bisect

def maxl(l, m, mx):
    l.sort(key=operator.itemgetter(1))
    
    m1, m2 = 0, 0
    pp = None
    for b, p in l:
        if p != pp:
            if 2 * p > m:
                break
            if m1 and m2 and m1 + m2 > mx:
                mx = m1 + m2
            m1, m2 = b, 0
            pp = p
        else:
            if b > m1:
                m1, m2 = b, m1
            elif b > m2:
                m2 = b
    if m1 and m2 and m1 + m2 > mx:
         mx = m1 + m2
         
    lp = list(p for(b, p) in l)
    lb = list(itertools.accumulate((b for (b, p) in l), max))
    for i, ((b, p), mb) in enumerate(zip(l, lb)):
        p1 = min(m - p, p - 1)
        k = bisect.bisect_right(lp, p1, 0, i)
        if k:
            x = b + lb[k - 1]
            if x > mx:
                mx = x
    return mx

   
fc = []
fd = []

n, c, d = map(int, input().split())
for _ in range(n):
    b, p, m = input().split()
    b, p = int(b), int(p)
    f, cd = (fc, c) if m == 'C' else (fd, d)
    if p <= cd:
        f.append((b, p))

mx = 0
if fc and fd:
    bc, pc = max(fc, key=operator.itemgetter(0))
    bd, pd = max(fd, key=operator.itemgetter(0))
    mx = bc + bd
mx = maxl(fc, c, mx)
mx = maxl(fd, d, mx)

print(mx)
