import math

t = int(input())
while t> 0:
    d = int(input())
    if d*d - 4*d < 0:
        print('N')
        t-=1
        continue
    if d!=0:
        a = (d + math.sqrt( d*d - 4*d ) ) / 2
        b = d / a
    else:
        a=0
        b=0
    print('Y %.9f %.9f'%(a,b))
    t-=1