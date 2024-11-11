from math import ceil
a=input()
c=ceil(len(a)/20)
d=ceil(len(a)/c)
d2=d*c-len(a)
s=0
s2=d
s3=c-d2
print(str(c)+" "+str(d))
for i in range(c):
    if i>=s3:
        print("*",end="")
        print(a[s:s2-1],end="")
        s,s2=s2-1,s2+d-1
    else:
        print(a[s:s2],end="")
        s,s2=s2,s2+d
    print()