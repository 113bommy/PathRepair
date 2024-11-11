r,g,b = map(int,input().split())
import math
if(r==1):
    r = r-1
elif(r>=2):
    r=r-2
time = 30
sum = r+g+b
#print(sum)
while(sum>0):

    if(g>0):
        #print('green')
        if(g>=2):
            g = g - 2
            sum=sum-2
        else:
            sum=sum-g
            g = g - 1
    time = time + 1
    if(sum<=0):
        break

    #print(sum,g,time)

    if(b>0):
        #print('blue')
        if(b>=2):
            b = b - 2
            sum=sum-2
        else:
            sum=sum-b
            b = b - 1
    time = time + 1
    if(sum<=0):
        break

    #print(sum, b, time)
    if(r>0):
        if(r>=2):
            r = r - 2
            sum=sum-2
        else:
            sum=sum-r
            r = r - 1
    time = time + 1
    if(sum<=0):
        break

    #print(sum, r, time)


print(time)