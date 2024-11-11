f = input()
h, m = input().split(':')
if int(m) > 59:
    m = '0' + m[1]
if f == '12' and not 0 < int(h) < 13:
    h = '0' + h[1] if int(h[1]) else '10'
if f == '24' and not 0 <= int(h) < 24:
    h = '0' + h[1] if int(h[1]) else '10'
print('{:0>2}:{:0>2}'.format(h, m))
