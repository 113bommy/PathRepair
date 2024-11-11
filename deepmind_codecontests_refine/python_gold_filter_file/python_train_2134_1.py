n,m=map(int,input().split())
a1,b1=map(int,input().split())
a2,b2=map(int,input().split())
ar1=n*m
ar2=(a1*b1)+(a2*b2)
a=a1+a2
b=a1+b2
c=a2+b1
d=b1+b2
t=1
def fu(su,q,w,n,m):
        t=1
        mi=min(n,m)
        ma=max(n,m)
        if(su<=mi):
                if(q<=ma and w<=ma):
                        return t
                else:
                        t=0
                        return t

        elif(su<=ma):
                if(q<=mi and w<=mi):
                        return t
                else:
                        t=0
                        return t
        else:

                t=0
                return t
        
        
z1=fu(a,b1,b2,n,m)
z2=fu(b,b1,a2,n,m)
z3=fu(c,a1,b2,n,m)
z4=fu(d,a1,a2,n,m)
#print(t)
if((z1==1 or z2==1 or z3==1 or z4==1) and ar1>=ar2):
        print("YES")
else:
        print("NO")
        
