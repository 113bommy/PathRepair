from math import *
n=int(input())
a=[int(x) for x in input().split()]
a.sort()
l=[True for i in range(n)]
c=0
for i in range(n):
    if a[i]==0 or l[i]==False:
        continue
    for j in range(i+1,n):
        if a[j]%a[i]==0:
            l[j]=False
    c+=1
print(c)    
        