a,m=map(int,input().split())
import math
s=math.log(m,2)
i=0
while i<int(s)+2:
    if (a*(2**i)) %m==0:
        print('Yes')
        break
    elif i<int(s)+1:
        i+=1
        continue
    else:
        print('No')
        i+=1 
