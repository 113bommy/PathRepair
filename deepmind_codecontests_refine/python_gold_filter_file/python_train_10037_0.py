s = list(input())

sans = []
for i in s:
    if len(sans) == 0:
        sans.append((i, 1))
    else:
        tmp, cnt = sans.pop()
        if tmp == i:
            sans.append((i, cnt + 1))
        else:
            sans.append((tmp, cnt))
            sans.append((i, 1))

sans = list(map(lambda x: [x[0], 1] if x[1] == 1 else [x[0], 2], sans))
for i in range(len(sans) - 1):
    if sans[i][1] == 2 and sans[i + 1][1] == 2:
        sans[i + 1][1] = 1
print("".join(map(lambda x: x[0] * x[1], sans)))
