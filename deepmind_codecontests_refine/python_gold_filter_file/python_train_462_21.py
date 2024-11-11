from math import sqrt
from math import ceil

rxyxdyd = input()
r, x, y, xd, yd = [int(i) for i in rxyxdyd.split(" ")]
dis = sqrt( (xd-x)**2 + (yd-y)**2 )
n = ceil(dis / (2*r))
print(n)
    
