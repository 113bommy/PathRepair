a,b,x=map(int,input().split())
c=0
if a%x==0:
    c=1
print((b//x)-(a//x)+c)