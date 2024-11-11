import math

n=int(input())

m=int(input())
a=[]
for i in range(n):
    a.append(int(input()))
a.sort()
M=a[n-1]+m
temp=n-2
while(temp>-1):
    k=(a[n-1]-a[temp])
    if(k):
        if(m-k>0):
            m=m-k
            a[temp]=a[n-1]
        else:
            a[temp]+=m
            m-=m
            break
    temp-=1
#print(m,a)
m=int(math.ceil(m/n))
print(a[n-1]+m," ",M)
