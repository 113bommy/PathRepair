n = int(input())
x0, y0 = map(int, input().split())
Nord = 10 ** 9 + 1
fNord = '-'
East = 10 ** 9 + 1
fEast = '-'
South = -10 ** 9 - 1
fSouth = '-'
West = -10 ** 9 - 1
fWest = '-'

NE = 10 ** 9 + 1
fNE = '-'
NW = 10 ** 9 + 1
fNW = '-'
SE = -10 ** 9 - 1
fSE = '-'
SW = -10 ** 9 - 1
fSW = '-'

for i in range(n):
    f, x, y = input().split()
    x = int(x)
    y = int(y)
    if x == x0:
        if y0 < y < Nord:
            fNord = f
            Nord = y
        elif y0 > y > South:
            fSouth = f
            South = y
    if y == y0:
        if x0 < x < East:
            fEast = f
            East = x
        elif x0 > x > West:
            fWest = f
            West = x
            
    if x + y == x0 + y0:
        if y0 < y < NW:
            fNW = f
            NW = y
        elif y0 > y > SE:
            fSE = f
            SE = y
    if x - y == x0 - y0:
        if y0 < y < NE:
            fNE = f
            NE = y
        elif y0 > y > SW:
            fSW = f
            SW = y
ans  = False
if fSW == 'Q' or fSE == 'Q' or fNW == 'Q' or fNE == 'Q':
    ans = True
if fNord == 'Q' or fSouth == 'Q' or fWest == 'Q' or fEast == 'Q':
    ans = True
if fSW == 'B' or fSE == 'B' or fNW == 'B' or fNE == 'B':
    ans = True
if fNord == 'R' or fSouth == 'R' or fWest == 'R' or fEast == 'R':
    ans = True

#print(fSW, fSE, fNW, fNE) 
#print(fNord, fSouth, fWest, fEast)
print('YES' if ans else 'NO')