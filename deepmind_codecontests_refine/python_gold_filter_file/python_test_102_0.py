for _ in range(int(input())):
    y, x = list(map(int, input().split()))
    s = str(input())
    dif = [0, 0]
    maxy = 0
    maxx = 0
    miny = 0
    minx = 0
    y_taken = 1
    x_taken = 1
    for i in range(len(s)):
        if s[i] == "U":
            dif[0] -= 1
        elif s[i] == "D":
            dif[0] += 1
        elif s[i] == "R":
            dif[1] += 1
        else:
            dif[1] -= 1
        if dif[0] > maxy:
            maxy = dif[0]
        elif dif[0] < miny:
            miny = dif[0]
        elif dif[1] >maxx:
            maxx = dif[1]
        elif dif[1] < minx:
            minx = dif[1]
        y_taken = 1 + abs(miny) + maxy
        x_taken = 1 + abs(minx) + maxx
        if y_taken > y or x_taken > x:
            if s[i] == "U":
                y_taken -= 1
                miny += 1
            elif s[i] == "D":
                y_taken -=1
                maxy -= 1
            elif s[i] == "R":
                x_taken -= 1
                maxx -=1
            else:
                x_taken -= 1
                minx += 1
            break
    diapos = [1-miny,y -maxy,1-minx,x-maxx] #ymin ymax xmin xmax
    # print(diapos)
    ans = [0,0]
    if dif[0] > 0:
        ans[0] = min(diapos[0],diapos[1])
    else:
        ans[0] = max(diapos[0],diapos[1])
    if dif[1] > 0:
        ans[1] = min(diapos[2],diapos[3])
    else:
        ans[1] = min(diapos[2], diapos[3])
    print(*ans)


