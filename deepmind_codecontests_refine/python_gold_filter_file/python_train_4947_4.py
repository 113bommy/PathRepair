x = input()
y = input()
a = ""
b = ""
flag = 0
for i in range(0,len(x)):
    if flag != 0 : a = a + x[i]
    elif x[i] != '0':
        flag = 1
        a = a + x[i]
flag = 0
for i in range(0,len(y)):
    if flag != 0 : b = b + y[i]
    elif flag == 0 and y[i] == 0: continue
    elif y[i] != '0':
        flag = 1
        b = b + y[i]
len1 = len(a)
len2 = len(b)


if len1 > len2: print(">")
elif len2 > len1: print("<")
else:
    flag = 0
    for i in range(0,len1):
        if flag == 1: break
        if a[i] > b[i]:
            print(">")
            flag = 1
        elif b[i] > a[i]:
            print("<")
            flag = 1
    if flag == 0:
        print("=")