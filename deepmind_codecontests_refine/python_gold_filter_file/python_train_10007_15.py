h, m = input().split(':')
res = h[::-1]
if res < '60' and m < res:
    print(h, res, sep=':')
else:
    res = '60'
    while not res < '60':
        h_int = (int(h) + 1) % 24
        h = ('0' if h_int < 10 else '') + str(h_int)
        res = h[::-1]
    print(h, res, sep=':')