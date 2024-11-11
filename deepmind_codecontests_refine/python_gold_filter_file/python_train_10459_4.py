import math
a, b=map(int,input().split())
xs=a-b
if xs<0:
    print(0)
elif xs==0:
    print('infinity')
else:
    x=int(math.sqrt(xs))
    count=0
    for i in range(1,x+1):
        if xs%i==0:
            if a%i==b:
                count+=1
            
            if i*i!=xs:
               ys=xs//i
               if a%ys==b:
                   count+=1
    
    print(count)
                             