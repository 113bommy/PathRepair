a = int(input())
b = int(input())
c = a+b 
a = str(a)
b = str(b)
c = str(c)
a = a.replace('0','')
b = b.replace('0','')
c = c.replace('0','')
a = int(a)
b = int(b)
c = int(c)
c1 = a+b
if c == c1:
    print('YES')
else:
    print('NO')