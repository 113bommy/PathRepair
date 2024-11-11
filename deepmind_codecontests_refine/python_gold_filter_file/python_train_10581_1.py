from math import*
sum=int()
mi=1000
a,b=map(int,input().split())
for i in range(1,a+1,1):
    x,y=map(int,input().split())
    sum=x/y
    if(sum<mi):
        mi=sum
print("%.8f" % (mi*b))
