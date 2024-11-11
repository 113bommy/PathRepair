import sys
n=int(input())
z=list(map(int,input().split()))
z.sort()
last=0
for i in range(n):
    if z[i]-last>=2:
        z[i]=last+1
        last+=1
    else:
        last=z[i]
print(z[-1]+1)