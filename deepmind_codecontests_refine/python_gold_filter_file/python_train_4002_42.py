line = input()
a = 0
b = 0
c = 0
if len(line) < 5:
    print('Too weak')
else:
    for i in range(len(line)):
        if line[i].isupper() == True:
            a = 1
        if line[i].islower() == True:
            b = 1
        if line[i].isdigit() == True:
            c = 1
    if a==1 and b==1 and c==1:
        print('Correct')
    else:
        print('Too weak')