

phase = 0
a, b, c = (0, 0, 0)

pat = input()
for ch in pat:
    if ch == '+': 
        phase = 1
        continue
    if ch == '=': 
        phase = 2
        continue

    # core
    if phase == 0 and ch == '|':
        a += 1
    elif phase == 1 and ch == '|':
        b += 1
    elif phase == 2 and ch == '|':
        c += 1

if (a+b-c) == 2:
    if a >= b:
        a -= 1
    else:
        b -= 1
    c += 1
    print('|'*a + '+' + '|'*b + '=' + '|'*c)
elif (a+b-c) == -2:
    a += 1
    c -= 1
    print('|'*a + '+' + '|'*b + '=' + '|'*c)
elif (a+b-c) == 0:
    print('|'*a + '+' + '|'*b + '=' + '|'*c)
else:
    print("Impossible")