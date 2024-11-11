while True:
    try:
        b = input()
    except:
        break
    if 'the' in b or 'this' in b or 'that' in b:
        print(b)
    for i in range(1,26):
        c = ''
        for j in b:
            if(j == 'z'):
                c += ('a')
            elif(str.isalpha(j) == 1):
                c += (chr(ord(j) + 1))
            else:
                c += j
        if 'the' in c or 'this' in c or 'that' in c:
            print(c)
            break
        b = c