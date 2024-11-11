from fractions import gcd
a1,b1,a2,b2,l,r=map(int,input().split())

if b1<l:
    b1=(b1-l)%a1+l
if b2<l:
    b2=(b2-l)%a2+l
ks1=(l-b1)/a1
ke1=(r-b1)/a1
ks2=(l-b2)/a2
ke2=(r-b2)/a2

g=gcd(a1,a2)
var=a1/g*a2
lst1=[]
lst2=[]
ks1=max(b1,b2)

m=min(1+r,var+ks1)
while b1!=b2 and m>b1:
    if b1<b2:
        b1=(b1-b2)%a1+b2
    else:
        b2=(b2-b1)%a2+b1
if(m>b1):
    print (int(1+(r-b1)//var))
else:
    print ("0")



