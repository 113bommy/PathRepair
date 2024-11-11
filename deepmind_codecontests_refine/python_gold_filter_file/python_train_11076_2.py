s = input()
metalPositions = []

i = 0
while True:
    i = s.find("metal", i)
    if i == -1:
        break;
    metalPositions.append(i)
    i += 5

count = 0
beg = 0
i = 0
while True:
    i = s.find("heavy", i)
    if i == -1:
        break
    i += 5
    for j in range(beg, len(metalPositions)):
        if metalPositions[j] >= i:
            count += len(metalPositions) - j
            beg = j
            break
    
print(count)