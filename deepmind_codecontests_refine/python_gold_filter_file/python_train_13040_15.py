t = int(input())

nLst = []

candies, oranges = [], []

for z in range(t):
    ni = int(input())
    nLst.append(ni)
    candies_i = []
    candies_i = input().split()
    for x in range(ni):
        candies_i[x] = int(candies_i[x])
    oranges_i = []
    oranges_i = input().split()
    for y in range(ni):
        oranges_i[y] = int(oranges_i[y])
    candies.append(candies_i)
    oranges.append(oranges_i)

for i in range(t):
    moves = 0
    min_c = min(candies[i])
    min_o = min(oranges[i])
    
    if max(candies[i]) == min(candies[i]) and max(oranges[i]) == min(oranges[i]):
        moves = 0
        print(moves)
        continue
    
    elif max(candies[i]) != min(candies[i]) and max(oranges[i]) != min(oranges[i]):   
        for j in range(nLst[i]):
            if candies[i][j] > min_c and oranges[i][j] > min_o:
                change = min(candies[i][j] - min_c, oranges[i][j] - min_o)
                moves += change
                candies[i][j] -= change
                oranges[i][j] -= change
                if candies[i][j] - min_c > 0:
                    tmpChange = candies[i][j] - min_c
                    moves += tmpChange
                    candies[i][j] -= tmpChange
                if oranges[i][j] - min_o > 0:
                    tmpChange = oranges[i][j] - min_o
                    moves += tmpChange
                    oranges[i][j] -= tmpChange
            else:
                tmpDelta = candies[i][j] - min_c
                moves += tmpDelta
                candies[i][j] -= tmpDelta
                tmpDelta = oranges[i][j] - min_o
                moves += tmpDelta
                oranges[i][j] -= tmpDelta

    elif max(oranges[i]) != min(oranges[i]) and max(candies[i]) == min(candies[i]):
        for j in range(nLst[i]):
            tmpDel = oranges[i][j] - min_o
            moves += tmpDel
            oranges[i][j] -= tmpDel

    elif max(candies[i]) != min(candies[i]) and max(oranges[i]) == min(oranges[i]):
        for j in range(nLst[i]):
            tmpD = candies[i][j] - min_c
            moves += tmpD
            candies[i][j] -= tmpD
    else:
        continue
    
    print(moves)
