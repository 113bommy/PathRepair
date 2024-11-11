import math as ma
t=int(input())
for i in range(t):
    a,b=map(int,input().split())
    se=0
    ee=0
    so=0
    eo=0
    if(a%2==0):
        se=a
        so=a+1
    else:
        se=a+1
        so=a 
    if(b%2==0):
        ee=b 
        eo=b-1
    else:
        ee=b-1
        eo=b 
    so=-(ma.ceil((eo-so+1)/2))*(2*so+2*(ma.ceil((eo-so+1)/2)-1))
    se=(ma.ceil((ee-se+1)/2))*(2*se+2*(ma.ceil((ee-se+1)/2-1)))
    print(int((se+so)//2))