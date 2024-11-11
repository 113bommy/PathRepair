import math
n = [int(i) for i in input().split(" ")]
data=[int(i) for i in input().split(" ")]
data.sort()
data.reverse()
p,s=0,0
for i in range(0,n[0]-1):
    if data[i]<=data[i+1]  and data[i]>1:
        s+=data[i+1] + 1 - data[i]
        data[i+1]=data[i]-1
    if data[i]==1:
        s+=data[i+1]-1
        data[i+1]=1
    
for i in range(n[0]-1):
    if data[i]>1:
        s+=data[i+1]

print(s)




