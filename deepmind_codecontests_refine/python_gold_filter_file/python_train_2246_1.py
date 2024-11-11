a=input()
b=input()
c=int(a)+int(b)
c=str(c)
while ('0' in a) or ('0' in b) or ('0' in c):
    a=a.replace('0','')
    b=b.replace('0','')
    c=c.replace('0','')
a=int(a)
b=int(b)
c=int(c)
if a+b==c:
    print('YES')
else:
    print('NO')