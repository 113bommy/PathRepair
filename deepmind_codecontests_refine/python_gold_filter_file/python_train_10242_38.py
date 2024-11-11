bulb = [[1, 1, 1], [1, 1, 1], [1, 1, 1]]

for i in range(3):
    a, b, c = input().split()

    if int(a) % 2 == 1:
        if i == 0:
            bulb[0][0] += 1
            bulb[0][1] += 1
            bulb[1][0] += 1
        if i == 1:
            bulb[1][0] += 1
            bulb[1][1] += 1
            bulb[0][0] += 1
            bulb[2][0] += 1
        if i == 2:
            bulb[2][0] += 1
            bulb[1][0] += 1
            bulb[2][1] += 1
    if int(b) % 2 == 1:
        if i == 0:
            bulb[0][0] += 1
            bulb[0][1] += 1
            bulb[0][2] += 1
            bulb[1][1] += 1
        if i == 1:
            bulb[1][1] += 1
            bulb[0][1] += 1
            bulb[1][0] += 1
            bulb[1][2] += 1
            bulb[2][1] += 1
        if i == 2:
            bulb[2][1] += 1
            bulb[1][1] += 1
            bulb[2][0] += 1
            bulb[2][2] += 1
    if int(c) % 2 == 1:
        if i == 0:
            bulb[0][2] += 1
            bulb[0][1] += 1
            bulb[1][2] += 1
        if i == 1:
            bulb[1][2] += 1
            bulb[0][2] += 1
            bulb[2][2] += 1
            bulb[1][1] += 1
        if i == 2:
            bulb[2][2] += 1
            bulb[1][2] += 1
            bulb[2][1] += 1


for i in range(3):
    for j in range(3):
        if bulb[i][j] % 2 == 0:
            bulb[i][j] = 0
        else:
            bulb[i][j] = 1
        print(bulb[i][j], end='')
    print()
