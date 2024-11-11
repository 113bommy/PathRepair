def gcd(a,b):
    if b==0:
        return a
    else:
        return gcd(b,a%b)
s,a,h=map(int,input().split(" "))
flag=True;ans=0
while(flag):
    an=gcd(s,h)
    if an>h:
        ans=1
        flag=False
        break
    h-=an
    an=gcd(a,h-ans)
    if(an>h):
        ans=0
        flag=False
        break
    h-=an
print(ans)
