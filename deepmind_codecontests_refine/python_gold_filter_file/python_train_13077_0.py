
import math 

a ,b = map(int,input().split())
num = 1 
ele = str(num)

for each in range ( a+1 , b+1 ):
    num = num*each
    ele = str(num)
    if(num%10==0):
        break

if( a==0 and b==0):
    print(1)
else:
    print(ele[-1] )

