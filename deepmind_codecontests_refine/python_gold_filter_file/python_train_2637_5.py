n=input()
m=list(map(int,input().split()))
a=m.count(4)
b=m.count(3)
c=m.count(2)
d=m.count(1)
if d-b==0:
    t =(a + b)+((c+1)//2)
elif d-b>0:
    if c%2==0:
        t = a + b + (((d - b +3) // 4)) + ((c// 2))
    else:
        t=a+b+((c//2))+(((d+5-b)//4))
else:
    t=(a+b)+((c+1)//2)
print(t)