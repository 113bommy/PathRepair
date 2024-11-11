r = int (input ())
g = 0
for h in range (1, r+1):
    g = g + h
    if g == r:
        print ('YES')
        break
else:
    print ('NO')

