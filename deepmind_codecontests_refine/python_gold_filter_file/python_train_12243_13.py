s = input()
if s == s[:-1]:
    print(0)
    exit()
h = int(s[:2])
m = int(s[3::])
H = ''
M = ''
k = 0
while s!=s[::-1]:
    m += 1
    if m == 60:
        m = 0
        h += 1
    if h == 24:
        h = 0
    if h < 10:
        H = '0' + str(h)
    else:
        H = str(h)
    if m < 10:
        M = '0' + str(m)
    else:
        M = str(m)
    s = H + M
    k += 1

print(k)