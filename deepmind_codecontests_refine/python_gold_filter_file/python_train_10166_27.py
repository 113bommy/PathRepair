
p,y= [int(x) for x in input().split()]
import math as m

for i in range(y, p, -1):
    for d in range(2, min( int(m.sqrt(i))+1, p+1 )):
        if i % d ==0:
            break
    else:
        print(i)
        break
else:
    print(-1)
