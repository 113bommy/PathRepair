def max(x,y):
    if x>y:return x
    else:return y

a=int(input())
b=int(input())
c=int(input())
if a==1:print(max(b+2,c*(b+1)))
else:
    if b > 1:print(max(a*b*c,a*(b+c)))
    else:print(max(a*(c+1),c*(a+1)))