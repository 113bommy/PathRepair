t=int(input())
d=0
if t>=100:
    d+=int(t/100)
    t=t%100
if t>=20:
    d+=int(t/20)
    t=t%20
if t>=10:
    d+=int(t/10)
    t=t%10
if t>=5:
    d+=int(t/5)
    t=t%5
if t>=1:
    d+=int(t/1)
    t=t%1
print(d)