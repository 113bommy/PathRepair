
T1,T2 = map(int,input().split())
A1,A2 = map(int,input().split())
B1,B2 = map(int,input().split())

d1 = A1*T1-B1*T1
d2 = A2*T2-B2*T2

import sys
if d1+d2 == 0:
    print('infinity')
    sys.exit()
elif d1*d2 > 0 or (abs(d1)-abs(d2)>0 and d1*d2<0):
    print(0)
    sys.exit()
    
else:
    start = abs(d1)
    delta = abs(d2+d1)
    ans = start//delta * 2
    if (start%delta)!=0:
        ans += 1
    print(ans)
    
    
    

    