s = input()
l = s.split(':')
if l[1] >= l[0][::-1]:
    l[0] = str(int(l[0]) + 1)
if l[0] == '24':
    l[0] = '00'
if len(l[0])==1:
    l[0] = '0' + l[0]
if l[0][1] >= '6':
    if l[0][0] == '0':
        print('10:01')
    else:
        print('20:02')
else:
    print(l[0]+':'+l[0][::-1])