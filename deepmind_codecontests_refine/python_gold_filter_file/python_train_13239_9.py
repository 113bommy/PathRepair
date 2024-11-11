import math
s=input()
s1=int(s,2)
if(s1==1 or s1==0):
    print(0)
elif(s1<=4):
    print(1)
else:
    count=2
    temp=16
    while(True):
        if(temp>=s1):
            break
        else:
            temp*=4
            count+=1
    print(count)