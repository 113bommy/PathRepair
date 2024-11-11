def mod(x, y):
    temp = x
    x = y
    y = temp%y
    return (x, y)
    

t = input()
for i in range(int(t)):
    k = input()
    found = False
    zer = False
    num1 = k.split(' ')
    num = []
    for j in range(len(num1)):
        num.append(int(num1[j]))
    for j in range(len(num)):
        if num[j] == 0 and num[1-j] != 1:
            zer = True
            break
        elif num[j] == 0 and num[1-j] == 1:
            found =True
            break
    if zer or found:
        break
    a, b = num[0], num[1]
    while(b != 0):
        if a == 1 or b == 1:
            found = True    
            break
        t = mod(a, b)
        a = t[0]
        b = t[1]
    if not found:
        print("infinite")
    else:
        print("finite")