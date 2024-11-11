#aba,123;1a;0
s = list(input())
l = len(s)
for i in range(l):
    if s[i]==',':
        s[i] = ';'
s = ''.join(s)
s = s.split(';')
no = []
w = []
for i in s:
    try:
        if not (len(i)>1 and i[0]=='0'):
            n = int(i)
            no.append(n)
        else:
            w.append(i)
    except ValueError:
         w.append(i)
if len(no):
    print ('"',end='')
    for i in range(len(no)-1):
        print (no[i], end= ',')
    print (no[-1], end='')
    print ('"')
else:
    print ('-')
no = w
if len(no):
    print ('"',end='')
    for i in range(len(no)-1):
        print (no[i], end= ',')
    print (no[-1], end='')
    print ('"')
else:
    print ('-')
