l,b=map(int,input().split())
x=0
while(l<=b):
    l=3*l
    b=2*b
    x+=1
print(x)