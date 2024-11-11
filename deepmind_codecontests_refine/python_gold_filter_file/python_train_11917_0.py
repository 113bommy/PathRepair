n=int(input())
h=0
r=n
for i in range(1,n+1):
    x=i*(i+1)//2
    if(r<x):
        break
    else:
        h=h+1
        r=r-x
print(h)
