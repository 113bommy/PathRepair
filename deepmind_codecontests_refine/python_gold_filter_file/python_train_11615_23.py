f = input()
h, m = input().split(':')

if f == '12':
    if h == '00':
        h = '01'
    elif int(h) > 12:
        if h[1] == '0':
            h = '10'
        else:
            h = '0' + h[1]

if f == '24' and int(h) > 23:
    h = '1' + h[1]

if int(m) > 59:
    m = '3' + m[1]

print(h + ':' + m)