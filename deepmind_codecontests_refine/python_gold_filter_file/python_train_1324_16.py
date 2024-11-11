from fractions import Fraction
ar=list(map(int,input().split()))
n=max(ar)
s=((6-n)+1)%6
if s==0:
    print('1/1')
else:
    print(Fraction(s,6))
   