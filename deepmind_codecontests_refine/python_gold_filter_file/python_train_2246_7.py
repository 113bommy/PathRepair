a = input()
b = input()
x = int(a)
y = int(b)
c = x + y
c = str(c)
while '0' in a or '0' in b or '0' in c:
    a = a.replace('0', '')
    b = b.replace('0', '')
    c = c.replace('0', '')
x = int(a)
y = int(b)
c = int(c)
if c == x + y:
    print('YES')
elif c != x + y:
    print('NO')
