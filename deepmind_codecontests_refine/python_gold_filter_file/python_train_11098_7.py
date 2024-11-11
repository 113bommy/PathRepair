(a,b)=map(str,input().split())
n=int(input())
if a == 'v':
    a=1
if a =='<':
    a=2
if a=='^':
    a=3
if a=='>':
    a=4
if b== 'v':
    b=1
if b=='<':
    b=2
if b=='^':
    b=3
if b=='>':
    b=4
a=int(a)
b=int(b)%4
k=n%4
po=(a+k)
protiv=a-k
if po%4!=protiv%4:
    if b==po%4:
        print('cw')
    else:
        print('ccw')
else:
    print('undefined')