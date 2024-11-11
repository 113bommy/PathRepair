def move(position):
    x = position[0]
    y = position[1]
    d = position[2]
    if d == "L":
        p = "DLUR"
    elif d == "R":
        p = "URDL"
    elif d == "U":
        p = "LURD"
    else:
        p = "RDLU"
    for i in range(4):
        if p[i] in grid[y][x]:
            d = p[i]
            if d == "L":
                print("L",end="")
                x -= 1
                break
            elif d == "R":
                print("R",end="")
                x += 1
                break
            elif d == "U":
                print("U",end="")
                y -= 1
                break
            else:
                print("D",end="")
                y += 1
                break
    return [x, y, d]

pos = [1,1,"R"]
grid = [["" for i in range(6)] for j in range(6)]
for i in range(9):
    inp = input()
    if i%2 == 0:
        for j in range(4):
            if inp[j] == "1":
                grid[i//2 + 1][j + 1] += "R"
                grid[i//2 + 1][j + 2] += "L"
    else:
        for j in range(5):
            if inp[j] == "1":
                grid[i//2 + 1][j + 1] += "D"
                grid[i//2 + 2][j + 1] += "U"
while True:
    pos = move(pos)
    if pos[0] == 1 and pos[1] == 1:
        break
print("")
