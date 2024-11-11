n, t = map(int, input().split())

matrix = [[0 for x in range(10)] for y in range(10)]
fullcups = 0

for x in range(10):
    for y in range(10):
        matrix[x][y] = 0

matrix[0][0] = t

for x in range(10):
    for y in range(10):
        if matrix[x][y] == 0:
            continue
        if matrix[x][y] > 1:
            flood = matrix[x][y] - 1
            matrix[x][y] = 1
            if x == 9:
                continue
            if y != 9:
                matrix[x+1][y+1] = matrix[x+1][y+1] + flood/2
            matrix[x+1][y] = matrix[x+1][y] + flood/2
            
for x in range(n):
    for y in range(n):
        if matrix[x][y] >= 1:
            fullcups = fullcups + 1
            
print(str(fullcups))