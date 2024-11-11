from fractions import Fraction
x=[int(j) for j in input().split()]
a=6-max(x)+1
b=6
if a/b==0:
    print(str(0)+'/'+str(b))
elif a/b==1:
    print(str(1)+'/'+str(1))
else:
    print(str(Fraction(a,b)))