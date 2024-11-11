a,b,c=[int(i) for i in input().split()]
x,y,z=[int(i) for i in input().split()]
import math
if a>=x and b>=y and c>=z:
    print('Yes')
elif a>=x and b>=y and c<z:
    if math.floor((a-x)/2)+math.floor((b-y)/2)>=z-c:
        print('Yes')
    else:
        print('No')
elif c>=z and b>=y and a<x:
    if math.floor((c-z)/2)+math.floor((b-y)/2)>=x-a:
        print('Yes')
    else:
        print('No')
elif a>=x and c>=z and b<y:
    if math.floor((a-x)/2)+math.floor((c-z)/2)>=y-b:
        print('Yes')
    else:
        print('No')
elif a>=x and b<y and c<z:
    if math.floor((a-x)/2)>=z-c+y-b:
        print('Yes')
    else:
        print('No')
elif b>=y and a<x and c<z:
    if math.floor((b-y)/2)>=z-c+x-a:
        print('Yes')
    else:
        print('No')
elif c>=z and b<y and a<x:
    if math.floor((c-z)/2)>=x-a+y-b:
        print('Yes')
    else:
        print('No')
elif c<=z and a<=x and b<y:
    print('No')
elif c<=z and a<x and b<=y:
    print('No')
elif c<z and a<=x and b<=y:
    print('No')
elif c<=z and a<x and b<y:
    print('No')
elif c<z and a<=x and b<y:
    print('No')
elif c<z and a<x and b<=y:
    print('No')
elif c<z and a<x and b<y:
    print('No')

    
    
