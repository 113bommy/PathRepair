x = int(input())
a, b = map(str, input().split(':'))
ct = 0
if x == 12:
    if (a in ['01', '02', '03', '04', '05', '06', '07', '08', '09', '10', '11', '12']):
        ct += 0
    else:
        ct += 1
        if (a[1] == '0'):
            a = '10'
        else:
            a = '0' + a[1]

if x == 24:
    if (a in ['01', '02', '03', '04', '05', '06', '07', '08', '09'] + [str(i) for i in range(10, 24)]):
        ct = ct
    else:
        ct += 1
        a = '0' + a[1]

if (b in ['01', '02', '03', '04', '05', '06', '07', '08', '09'] + [str(i) for i in range(10, 60)]):
    ct = ct
else:
    ct += 1
    b = '0' + b[1]

print(a+":"+b)
