s = input().strip()
all = 'abcdefghijklmnopqrstuvwxyz'
p = 0
t = True
for i in s:
    if i in all[0:p]:
        pass
    elif i == all[p]:
        if p < 25:
            p += 1
    else:
        t = False
        break
if t == True:
    print('YES' )
else:
    print('NO')