a = input()
b = input()

if len(a) < len(b):
    print(''.join(sorted(list(a), reverse = True)))
else:
    lst = sorted(list(a), reverse = True)
    temp = ''
    prefix = ''
    while len(lst) > 0:
        for x in range(len(lst)):
            temp = prefix + lst[x] + ''.join(sorted(lst[:x] + lst[x + 1:]))
            if temp <= b:
                prefix = prefix + lst[x]
                lst.remove(lst[x])
                break

    print(prefix)
    
