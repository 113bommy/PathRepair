from fractions import Fraction
l=list(map(int,input().strip().split(" ")))
max1=max(l)
b=6
a=1+(b-max1)
if (a==6):
    print("1/1")
elif(max1==0):
    print("0/1")
else:
    print(str(Fraction(a,b)))
