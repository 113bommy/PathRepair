# cook your dish here
def digsum(n):
    if(n<0):
        return False
    n=str(n)
    t=0
    for i in n:
        t+=int(i)
    return t
from math import ceil,floor
a,b,c=map(int,input().split())
x=[]
for i in range(1,82):
    y=(b*(i**a))+c
    if(digsum(y)==i and (0<y<10**9)):
        x.append(y)
print(len(x))
x.sort()
print(*x)