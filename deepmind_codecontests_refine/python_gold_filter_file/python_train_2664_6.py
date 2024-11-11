n=int(input())
k=n//7
k1=n%7
s='VIBGYOR'
s=s*k
if k1==1:
    s+='G'
elif k1==2:
    s+='GY'
elif k1==3:
    s+='IBG'
elif k1==4:
    s+='IBGO'
elif k1==5:
    s+='VIBGY'
elif k1==6:
    s+='VIBGYO'
print(s)