def isLegal(g):
    numX = sum(g[i].count('X') for i in range(3))
    numO = sum(g[i].count('0') for i in range(3))
    if numX-numO > 1 or numX-numO < 0:
        return False
    winners = whoWin(g)
    if len(set(winners)) > 1:
        return False
    if len(winners) > 0 and winners[0] == '0' and numX > numO:
        return False
    if len(winners) > 0 and winners[0] == 'X' and numX <= numO:
        return False
    return True

def whoWin(g):
    winners = []
    for i, j in ((0, 1), (1, 0), (1, 1), (1, 2), (2, 1)):
        if g[i][j] == '.':
            continue
        if i-1 >= 0 and i+1 < 3 and g[i-1][j] == g[i][j] and g[i+1][j] == g[i][j]:
            winners.append(g[i][j])
        if j-1 >= 0 and j+1 < 3 and g[i][j-1] == g[i][j] and g[i][j+1] == g[i][j]:
            winners.append(g[i][j])
    if g[1][1] != '.' and g[0][0] == g[1][1] and g[2][2] == g[1][1]:
        winners.append(g[1][1])
    if g[1][1] != '.' and g[0][2] == g[1][1] and g[2][0] == g[1][1]:
        winners.append(g[1][1])
    return winners

g = [list(input()) for i in range(3)]

if not isLegal(g):
    print('illegal')
    exit()

winners = whoWin(g)
if len(winners) > 0:
    print('the ' + ('first' if winners[0] == 'X' else 'second') + ' player won')
    exit()

numX = sum(g[i].count('X') for i in range(3))
numO = sum(g[i].count('0') for i in range(3))
if numX + numO == 9:
    print('draw')
elif numX <= numO:
    print('first')
else:
    print('second')
