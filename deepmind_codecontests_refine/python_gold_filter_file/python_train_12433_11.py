countX = 0
count0 = 0
data = []
winX = 0
win0 = 0
turn = -1
illegal = 0
for i in range(3):
    line = input()
    data.append(line)
    for j in range(3):
        if line[j] == 'X':
            countX += 1
        elif line[j] == '0':
            count0 += 1
#print(countX, count0)
if 0 <= countX - count0 <= 1:
    if countX - count0 == 0:
        turn = 0
    else:
        turn = 1
    #print(turn)
    for i in range(3):
        if data[i] == 'XXX':
            winX = 1
            #print('a')
        elif data[i] == '000':
            win0 = 1
            #print('a')
        if data[0][i] == data[1][i] == data[2][i] == 'X':
            winX = 1
            #print('b')
        elif data[0][i] == data[1][i] == data[2][i] == '0':
            win0 = 1
            #print('b')
    if data[0][0] == data[1][1] == data[2][2] or data[0][2] == data[1][1] == data[2][0]:
        if data[1][1] == 'X':
            winX = 1
            #print('c')
        elif data[1][1] == '0':
            win0 = 1
            #print('c')
    if winX == win0 == 1 or (winX == 1 and turn == 0) or (win0 == 1 and turn == 1):
        print('illegal')
    else:
        if winX == 1:
            print('the first player won')
        elif win0 == 1:
            print('the second player won')
        elif countX + count0 == 9:
            print('draw')
        elif turn == 1:
            print('second')
        else:
            print('first')
else:
    print('illegal')
    
