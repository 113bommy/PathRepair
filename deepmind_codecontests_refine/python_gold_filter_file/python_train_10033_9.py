import math
a=[]
for i in range(3001):
    a.append(0)
for i in range(3,3001,2):
    a[i]=1
for i in range(3,3001,2):
    if a[i]==1:
        for j in range(i*i,3001,i):
            a[j]=0
a[2]=1

a1=[]
for i in range(3001):
    if a[i]==1:
        a1.append(i)

def fun(n):
    #if n==1:
    #    return True
    if n>=2 and n<6:
        return False
    else:
        c=0
        for j in a1:
            if i%j==0:
                c+=1
            if c>2:
                return False
        if c==2:
            return True
        else:
            return False
        
n=int(input())

c=0
for i in range(1,n+1):
    if(fun(i)):
        #print(i)
        c+=1
                
print(c)