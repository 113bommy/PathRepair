a = input()
b = 0
if '1' not in a:
    print("no")
else:
    i = a.index('1')
    for k in range(i, len(a)):
        if a[k] == '0':
            b += 1
    if b >= 6:
        print("yes")
    else:
        print("no")