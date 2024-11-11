import math
hou,m=map(int,input().split()) 
h,d,c,n=map(int,input().split()) 
if hou in range(20,24): 
    print(math.ceil(h/n)*(4/5*c)) 
else: 
    fir=math.ceil(h/n)*c
    hd=20-hou-1;md=60-m 
    sec=(math.ceil(((h+(60*hd+md)*d)/n))*4*c)/5 
    print(min(fir,sec))