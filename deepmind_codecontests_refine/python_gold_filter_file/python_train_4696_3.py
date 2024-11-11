a,b,x,y=map(int,input().split())
def hcfnaive(a,b): 
    if(b==0): 
        return a 
    else: 
        return hcfnaive(b,a%b) 

s= hcfnaive(x,y)
h=x//s
c=y//s
k=a//h
z=b//c
if(k!=0 and z!=0):
    print(min(k,z))
else:
    print(0)