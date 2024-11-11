n = int(input())
b = 0
c = ''
f = ''
for i in range(n):
    a = input()
    c = c + a
x = 0
for i in range(len(c) // 5):
    if c[x:(x + 2)] == 'OO' and b <= 0:
        d = c[x:(x + 5)]
        d = d.replace('O', '+', 2)
        b = b + 1
        x = x + 5
        f = f + d
    elif c[(x + 3):(x + 5)] == 'OO' and b <= 0:
        d = c[x:(x + 5)]
        d = d[::-1]
        d = d.replace('O', '+', 2)
        d = d[::-1]
        b = b + 1
        x = x + 5
        f = f + d
    else:
        f = f + c[x:(x + 5)]
        x = x + 5
if '++' in f:
    print('YES')
    z = 0
    for i in range(len(f) // 5):
        g = f[z:z + 5]
        print(g)
        z = z + 5
else:
    print('NO')



