a = int(input())
b = int(input())
c = int(input())
d = int(input())
e = int(input())
f = int(input())
n = 0
if(e>f):
    n+=min(a,d)*e
    if(min(a,d) == a):
        d-=a
        n+=min(b,c,d)*f
        print(n)
    else:
        print(n)
else:
    n+=min(b,c,d)*f
    if(min(b,c,d)==d):
        print(n)
    else:
        d -= min(b,c)
        n+=min(a,d)*e
        print(n)