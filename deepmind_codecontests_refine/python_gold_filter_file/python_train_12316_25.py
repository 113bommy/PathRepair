a=input
k=int(a())
l=int(a())
m=int(a())
n=int(a())
d=int(a())
x=0
for i in range(1,d+1):
    if d>=k or d>=l or d>=m or d>=n:
        if (i%k==0 or i%l==0 or i%m==0 or i%n==0):
            x+=1
print(x)