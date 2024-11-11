def i2():
 return [int(i) for i in input().split()]

[n,h]=i2()
a=[]
for i in range(n):
 b=i2()
 a+=[[b[0],0],[b[1],1]]
a.sort()
a=a[::-1]
i=0
c=0
while a[i][1]==1 and h>0:
 h-=a[i][0]
 c+=1
 i+=1

if h>0:
 c+=h//a[i][0]
 if h%a[i][0]:c+=1
print(c)