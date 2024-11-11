s=input()
if s[0]=="0":
    h=int(s[1])
else:
    h=int(s[:2])
if s[3]=="0":
    m=int(s[4])
else:
    m=int(s[3:])
a=((h)*30+6*(5*m/60))%360
if str(a)[-1]=="0":
    a=int(a)
b=6*m
print(a,b)