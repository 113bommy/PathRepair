import math
from decimal import *

for _ in range(int(input())):
    n = int(input())
    s = str(input())
    pos1, pos0 = [],[]
    mrk = [0]*n
    for m in range(n):
        tot = len(pos0)+len(pos1)+1
        if(s[m]=='0'):
            if(not pos1):
                pos0.append(tot)
            else:
                tot = pos1.pop()
                pos0.append(tot)
        else:
            if(not pos0):
                pos1.append(tot)
            else:
                tot = pos0.pop()
                pos1.append(tot)
        mrk[m]= str(tot)
    print(len(pos0)+len(pos1))
    print(' '.join(mrk))