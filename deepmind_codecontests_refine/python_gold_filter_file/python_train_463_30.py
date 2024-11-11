a,b,c,d,e=map(int,input().split())
f=2*a;g=((b-d)**2+(e-c)**2)**0.5
print(0 if g==0 else int(g//f) if int(g)==g and g%f==0 else int((g//f)+1))
