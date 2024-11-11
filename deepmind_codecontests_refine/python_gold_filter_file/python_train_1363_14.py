import collections
from statistics import mean
max=0
s=input().split()
n,k=int(s[0]),int(s[1])
a=input().split()
a=[int(i) for i in a]
for i in range(0,n-k+1):
    #print(a[i:i+k])
    s=sum(a[i:i+k])
    m=s/k
    #print(s)
    if(m>max):
        max=m
    num=k
    for j in range(i+k,n):
        s+=a[j]
        num+=1
        m=s/num
        #print(m)
        if m>max:
            max=m
print(max)