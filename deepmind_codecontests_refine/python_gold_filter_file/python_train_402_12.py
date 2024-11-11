board = [[False]*1000001]*1000001
while True:
    m = int(input())
    if m == 0: break
    star = tuple(tuple(map(int, input().split())) for i in range(m))
    sx, sy = star[0]
    
    n = int(input())
    starlist = [tuple(map(int, input().split())) for i in range(n)]
    for i in range(n):
        board[starlist[i][0]][starlist[i][1]] = True
    for i in range(n):
        flag = True
        for j in range(len(star)-1):
            dx = starlist[i][0] + star[j+1][0] - sx
            dy = starlist[i][1] + star[j+1][1] - sy
            if dx < 0 or 1000000 < dx or dy < 0 or 1000000 < dy or board[dx][dy] == False:
                flag = False
                break

        if flag == True:
            print("{} {}".format(starlist[i][0] - sx, starlist[i][1] -sy))
            break
    