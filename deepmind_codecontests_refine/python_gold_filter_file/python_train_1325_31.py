from fractions import Fraction
y,w=map(int,input().split())
if(y==w==1):
    print('1/1')
else:
    if(y>w):
        maxim=y
    else:
        maxim=w
    print(Fraction(((6-maxim)+1),6))