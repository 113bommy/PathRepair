# -*-coding:utf-8-*-
a, b = input(), input()
m, n = (ord(a[i]) - ord(b[i]) for i in range(2))
p = max(abs(m), abs(n))
print(p)
while m != 0 or n != 0:
    r = ''
    if m < 0:
        r = 'R'
        m += 1
    elif m> 0:
        r = 'L'
        m -= 1
    if n < 0:
        r += 'U'
        n += 1
    elif n > 0:
        r += 'D'
        n -= 1
    print(r)
