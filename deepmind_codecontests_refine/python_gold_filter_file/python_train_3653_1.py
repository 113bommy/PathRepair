a, b, x = map(int, input().split())
s = ''
z = ''
o = ''
if x % 2:
    t = (x+1)//2
    while t:
        s += '01'
        a -= 1
        b -= 1
        t -= 1
    while a:
        z += '0'
        a -= 1
    while b:
        o += '1'
        b -= 1
    print(z+s+o)
else:
    x = x-1
    t = (x+1)//2
    while t:
        s += '01'
        a -= 1
        b -= 1
        t -= 1
    while a > 1:
        z += '0'
        a -= 1
    while b > 1:
        o += '1'
        b -= 1
    if a==1 and b==1:
        print(z+s+o+'10')
    elif not b:
        print(s+z+a*'0')
    else:
        print(b*'1'+o+s)