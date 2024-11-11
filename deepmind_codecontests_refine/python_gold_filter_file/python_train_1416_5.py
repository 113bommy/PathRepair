a=input()
h=int(a[:2])
m=int(a[3:])
if h>12:
    h-=12
if (h==12 or h==0) and m==0:
    print(0,0)
elif h==12 or h==0:
    print((m/60)*30,m*6)
else:
    print((h+m/60)*30,m*6)