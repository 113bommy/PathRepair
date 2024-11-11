from math import sqrt,ceil
n=int(input())
a=[]
b=[]
c=0
def commfact(a,b):
    for i in range(2,ceil(sqrt(min(a,b)))+1):
        if(a%i==0 and b%i==0):
            return(0)
    return(1)    
for i in range(2,ceil(sqrt(n))+1):
    if(n%i==0):
        c=c+1
        b=[i,int(n/i)]
        a.append(b)
for i in range(len(a)-1,-1,-1):
    if(a[i][1]%a[i][0]!=0 and a[i][0]%a[i][1]!=0 and commfact(a[i][1],a[i][0])):
        print(a[i][0],a[i][1])
        c=-1
        break
if(c!=-1):
    print(1,n)
