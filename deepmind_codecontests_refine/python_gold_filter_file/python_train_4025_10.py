hh, mm = map(int, input().split())
h, d, c, n = map(int, input().split())

from math import ceil
if hh<20:
    print(min( ceil((h+(60-mm+(20-hh-1)*60)*d)/n)*c*0.8, ceil(h/n)*c ))
else:
    print(ceil(h/n)*c*0.8)
