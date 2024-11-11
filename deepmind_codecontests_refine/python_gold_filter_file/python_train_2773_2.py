x=int(input())
a=input()
z=int(a[4])
c=10+z-7
if c==10:
    c=0
t=0
mm=a[3:]
hh=a[:2]
while '7' not in mm and '7' not in hh:
    mm1=int(mm)
    mm1+=-x
    hh1=int(hh)
    if mm1<0:
        h=abs(mm1)//60
        mm1+=60
        if abs(mm1)/60>0:
            hh1-=h+1
        else:
            hh1-=h
    if len(str(hh1))==1:
        hh1='0'+str(hh1)
    if len(str(mm1))==1:
        mm1='0'+str(mm1)
    mm=str(mm1)
    hh=str(hh1)
    t+=1
    #print(hh+':'+mm)
print(t)
