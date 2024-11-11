for i in range(int(input())):
    a = input()
    c = 0; li = []; z = 'Yes'
    for i in range(len(a)):
        li.append(ord(a[i]))
    b = min(li)
    for i in range(len(a)):
        if li.count(b) != 0:
            pass
        else:
            z = ''
            print('No')
            break
        b += 1
    if z == 'Yes':
        print('Yes')