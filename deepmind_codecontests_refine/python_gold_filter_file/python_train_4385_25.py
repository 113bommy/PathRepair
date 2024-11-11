x,y,z,t1,t2,t3=map(int,input().split())
a=abs(x-y)
b=abs(x-z)
ts=a*t1
te=(a+b)*t2+3*t3
if te>ts:
    print('NO')
else:
    print('YES')