import math
f=0
arr = []
t=int(input())
for i in range(0,t):
    a,b,k=input().split()
    a=int(a)
    b=int(b)
    k=int(k)
    f = a*(math.ceil(k/2))
    f -= b*(k//2)
    arr.append(f)
    f=0
for ar in arr:
    print(ar)