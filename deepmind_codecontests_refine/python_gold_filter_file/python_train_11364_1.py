import math
n=input()
n=int(n)
l=list(map(int,input().split()))
index=0
m=l[0]
for i in range(n):
    j=i+1
    if (l[i]//(max(abs(j-1),abs(n-j))))<m:
        m=(l[i]//(max(abs(j-1),abs(n-j))))

#print(math.floor(m/max(abs(i-1),abs(n-i))))
print(m)       