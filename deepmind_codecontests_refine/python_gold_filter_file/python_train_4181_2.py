for i in range(1, int(input())+1):
    a = input()
    c = 0; li = []; z = 'YES'
    for i in range(len(a)):
        li.append(ord(a[i]))
    b = min(li)
    for i in range(len(a)):
        if li.count(b) != 0:
            pass
        else:
            z = ''
            print('NO')
            break
        b += 1
    if z == 'YES':
        print('YES')