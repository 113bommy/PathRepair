hh,mm = input().split(' ')
hh = int(hh)
mm = int(mm)
h,d,c,n = input().split(' ')
h = int(h)
d = int(d)
c = int(c)
n = int(n)
if(hh<20):
    x = ((20-hh-1)*60+(60-mm))*d+h
    x = x/n
    if(x==int(x)):
        x = int(x)
    else:
        x = int(x)+1
    disa = (0.800)*c*x
    y = h/n
    if(y==int(y)):
        y = int(y)
    else:
        y = int(y)+1
    b = c*y*1.000
    ans = min(disa,b)
else:
    y = h/n
    if(y==int(y)):
        y = int(y)
    else:
        y = int(y)+1
    b = c*y*0.800
    ans = b
print(ans)


