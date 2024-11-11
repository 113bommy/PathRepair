a = int(input())
b = int(input())
c = int(input())
d = int(input())
e = int(input())
f = int(input())



ans = 0
if(e >= f):
    x = min(a,d)
    ans = ans + (e * x)
    a = a - x
    d = d - x
    y = min(b,c,d)
    ans = ans + (f * y)
    print(ans)
elif(f > e):
    y = min(b,c,d)
    ans = ans + (f * y)
    b = b - y
    c = c - y
    d = d - y
    x = min(a,d)
    ans = ans + (e * x)
    print(ans)