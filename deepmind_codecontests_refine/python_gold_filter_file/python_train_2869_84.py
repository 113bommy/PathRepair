k = int(input());
a= list()
for i in range(0,k,1):
    a.append(str(input()))
for s in a:
    if len(s) > 10:
        print(s[0] + str(len(s)-2) + s[-1])
    else:
        print(s)