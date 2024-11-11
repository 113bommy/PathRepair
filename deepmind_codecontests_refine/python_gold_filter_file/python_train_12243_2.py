h, m = map(int,input().split(':'))
c = 0
if h < 10 and m < 10:
    s = '0'+str(h)+':'+'0'+str(m)
elif h < 10 and m >= 10:
    s = '0'+str(h)+':'+str(m)
elif h >= 10 and m < 10:
    s = str(h)+':'+'0'+str(m)
else:
    s = str(h)+':'+str(m)
while s != s[::-1]:
    m += 1
    h += m // 60
    m = m % 60
    h = h % 24
    if h < 10 and m < 10:
        s = '0'+str(h)+':'+'0'+str(m)
    elif h < 10 and m >= 10:
        s = '0'+str(h)+':'+str(m)
    elif h >= 10 and m < 10:
        s = str(h)+':'+'0'+str(m)
    else:
        s = str(h)+':'+str(m)
    c +=1
print(c)