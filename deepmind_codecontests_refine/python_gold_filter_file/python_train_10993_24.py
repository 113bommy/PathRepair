##Sheldon, Leonard, Penny, Rajesh and Howard 
import math
n=int(input())
num=int(math.log(n/5+1)/math.log(2))
#print(num)
rem=n-5*(math.pow(2,num)-1)
#print(rem)
if rem==0:
    print('Howard')
else:
    rem2=rem/math.pow(2,num)
    #print(rem2)
    if 1>=rem2>0:
        print('Sheldon')
    elif 1<rem2<=2:
        print('Leonard')
    elif 2<rem2<=3:
        print('Penny')
    elif 3<rem2<=4:
        print('Rajesh')
    else:
        print('Howard')

