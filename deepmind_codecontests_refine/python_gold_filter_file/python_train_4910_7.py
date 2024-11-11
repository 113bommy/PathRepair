from sys import*
n=int(input())
a=[int(x)for x in input().split()]
b=[int(x)for x in input().split()]
if not max(b):print(n);exit()
if 1 in b:
    x=b.index(1)
    for i in range(x+1,n):
        if b[i]!=i-x+1:break
    else:
        for i in range(x):
            if b[i] and b[i]-(n-x+2+i)<0:break
        else:print(x);exit()
ex=0
for i in range(n):
    if b[i]:
        ex=max(ex,i-(b[i]-2))
print(n+ex)
