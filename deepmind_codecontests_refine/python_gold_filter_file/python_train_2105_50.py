from array import *
n=int(input())
s=list(input())
a=sorted(s)
x=0
y=0
for i in range(n):
    if a[i]=='L':
        x+=1
    elif a[i]=='R':
        y+=1
print(x+y+1)


