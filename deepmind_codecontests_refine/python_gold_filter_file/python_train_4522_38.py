s = input() #a8
t = input() #h1

steps = 0
moves = []
row_dist = int(t[1]) - int(s[1])
col_dist = ord(t[0]) - ord(s[0])

while(row_dist != 0 or col_dist != 0):

    if abs(row_dist) > abs(col_dist):
        if row_dist > 0:
            moves.append("U")
            steps += 1
            row_dist -= 1
        elif row_dist < 0:
            moves.append("D")
            steps += 1
            row_dist += 1
        else:
            break

    elif abs(row_dist) < abs(col_dist):
        if col_dist > 0:
            moves.append("R")
            steps += 1
            col_dist -= 1
        elif col_dist < 0:
            moves.append("L")
            steps += 1
            col_dist += 1
        else:
            break

    elif abs(row_dist) == abs(col_dist):
        for i in range(abs(col_dist)):
            if col_dist > 0 and row_dist > 0:
                moves.append("RU")
                steps += 1
                col_dist -= 1
                row_dist -= 1
            elif col_dist > 0 and row_dist < 0:
                moves.append("RD")
                steps += 1
                col_dist -= 1
                row_dist += 1
            elif col_dist < 0 and row_dist > 0:
                moves.append("LU")
                steps += 1
                col_dist += 1
                row_dist -= 1
            elif col_dist < 0 and row_dist < 0:
                moves.append("LD")
                steps += 1
                col_dist += 1
                row_dist += 1

print(steps)
for i in moves:
    print(i)