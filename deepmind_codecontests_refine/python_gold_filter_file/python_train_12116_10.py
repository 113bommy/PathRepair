l,r=map(int,input().split())
x=l^r 
a=2 
if(l==r):
    print(0)
else:
    while(a<=x):
        a=a*2 
        
    print(a-1)