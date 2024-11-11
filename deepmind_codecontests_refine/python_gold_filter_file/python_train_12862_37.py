inp = int(input())
res = []
flag = 0
for i in range (inp):
    stroke = input()
    stroke = stroke.split('|')
    if (stroke[0] == 'OO') & (flag == 0):
        stroke[0] = '++'
        flag = 1
    elif (stroke[1] == 'OO') & (flag == 0):
        stroke[1] = '++'
        flag = 1
    res.append(stroke[0] + '|' + stroke[1])
if flag == 1:
    print('YES')
    for i in res:
        print(i)
else:
    print('NO')

