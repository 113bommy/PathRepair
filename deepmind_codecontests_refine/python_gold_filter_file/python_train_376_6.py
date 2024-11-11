import math
n=int(input())
l=int(input())
h=(max(l,n)-min(l,n))-1
if(h%2==0):
    h=math.floor(h/2)

    
    l=math.floor((h*(h+1))/2)


    t=math.floor(((h+1)*(h+2))/2)
    t=t+l

    print(t)


else:
    h=math.floor(h/2)+1
    
    h=math.floor((h*(h+1)))

    print(h)