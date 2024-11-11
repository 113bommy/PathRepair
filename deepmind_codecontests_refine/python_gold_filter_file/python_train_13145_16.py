import sys
import math
def II():
	return int(sys.stdin.readline())
 
def LI():
	return list(map(int, sys.stdin.readline().split()))
 
def MI():
	return map(int, sys.stdin.readline().split())
 
def SI():
	return sys.stdin.readline().strip()
t = II()
for q in range(t):
    x,y = MI()
    a = LI()
    d = [0,0,0,0,0,0]
    if x == 0 and y == 0:
        print(0)
        continue
    elif x == 0:
        if y>0:
            d[1]+=y
        else:
            d[4]+=abs(y)
    elif y == 0:
        if x>0:
            d[5]+=x
        else:
            d[2]+=abs(x)
    elif x>0:
        if y>0:
            z = abs(x-y)
            if x>y:
                d[5]+=z
            else:
                d[1]+=z
            d[0]+=min(x,y)
        else:
            d[5]+=x
            d[4]+=abs(y)
    else:
        if y>0:
            d[2]+=abs(x)
            d[1]+=y
        else:
            z = abs(abs(x)-abs(y))
            if x<y:
                d[2]+=z
            else:
                d[4]+=z
            d[3]+=abs(max(x,y))
    old = [0,0,0,0,0,0]
    while old!=a:
        old = a[:]
        for i in range(6):
            a[i] = min(a[i], a[(i-1)%6]+a[(i+1)%6])
    ans = 0
    for i in range(6):
        ans+=d[i]*a[i]
    print(ans)




