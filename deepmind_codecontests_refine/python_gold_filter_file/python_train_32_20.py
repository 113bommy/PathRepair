n,x,y=map(int,input().split())
num=(y*n)/100
num1=(y*n)//100
z=num-num1
if z==0 and x<=num:
    print(num1-x)
elif z!=0 and x<=num:
    print(num1+1-x)
elif x>num:
    print(0)