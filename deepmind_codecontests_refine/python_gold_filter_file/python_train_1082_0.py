def can(d,a,b):
    d1=d
    mi=a[-1]
    ma=a[-1]
    while len(a)>0 and len(b)>0:
        if b[-1]<=mi:
            if abs(b[-1]-ma)<=d1:
                a.pop()
                if len(a)==0:
                    break
                ma=a[-1]
            else:
                b.pop()
                mi=a[-1]
                ma=a[-1]
        elif b[-1]>=ma:
            if abs(b[-1]-mi)<=d1:
                a.pop()
                if len(a)==0:
                    break
                ma=a[-1]
            else:
                b.pop()
                mi=a[-1]
                ma=a[-1]
        else:
            if abs(ma-mi)+min(abs(b[-1]-mi),abs(b[-1]-ma))<=d1:
                a.pop()
                if len(a)==0:
                    break
                ma=a[-1]
            else:
                b.pop()
                mi=a[-1]
                ma=a[-1]
    return len(a)==0  
n,m=map(int,input().split())
s=list(map(int,input().split()))[::-1]
s1=list(map(int,input().split()))[::-1]
high=(10**11)+1
low=0
while high-low>1:
    mid=(high+low)//2
    if can(mid,s1.copy(),s.copy()):
        high=mid
    else:
        low=mid
if can(low,s1,s):
    print(low)
else:
    print(high)
    
