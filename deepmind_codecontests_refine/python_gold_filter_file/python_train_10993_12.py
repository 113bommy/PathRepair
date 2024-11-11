import math
l=["Sheldon", "Leonard", "Penny", "Rajesh", "Howard" ]
n=int(input())
a=[5]
if(n<=5):
    print(l[n-1])
else:
    i=2
    while(a[-1]<n):
        a.append(a[-1]+i*5)
        i*=2
    d=a[-1]-a[-2]
    x=d//5
    k=math.ceil((n-a[-2])/x)
   # print(a,x,d)
    print(l[k-1])
    
