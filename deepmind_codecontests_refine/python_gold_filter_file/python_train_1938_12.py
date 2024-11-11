import math
c1,c2=input().split(" ")
c1=int(c1)
c2=int(c2)
jp=int(input())
x=0
h=0
while x<jp :
    a,b,c=input().split(" ")
    a=int(a)
    b=int(b)
    c=int(c)
    p=a*a+b*b
    d=math.sqrt(p)
    if(d+c<=c1 and d-c>=c1-c2):
        h+=1
        x+=1
    else:
        x+=1
print(h)
