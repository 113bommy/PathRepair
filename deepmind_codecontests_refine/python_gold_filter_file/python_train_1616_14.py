R = lambda : input().split()
n = int(input())
v = list(R())

import math
if '0' in v:
    print(0)
else:
    i = 0
    j = '1'
    for a in v:
        if a == '1'+'0'*(len(a)-1):
            i += len(a)-1
        else:
            j = a
    print(j+'0'*i)
        