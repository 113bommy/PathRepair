a = input()
b = input()
c = 0
v = 0
m = 'D C S H'
z = '2 3 4 5 6 7 8 9 T J Q K A'

for i in range(len(z)):
    if z[i] in a and z[i] in b:
        v += 1
    else:
        c += 1
for i in range(len(m)):
    if m[i] in a and m[i] in b:
        v += 1
    else:
        c += 1
if v >= 1:
    print('YES')
elif c >= 2:
    print('NO')