for q in range(int(input())):
    k = int(input())
    f = []
    left = -100000
    down = -100000
    right = 100000
    up = 100000
    for t in range(k):
        f.append(tuple(map(int, input().split())))
    for n in range(k):
        if f[n][2] == 1 and f[n][3] == 1 and f[n][4] == 1 and f[n][5] == 1:
            continue
        else:
            if f[n][2] == 0 and f[n][0] > left:
                left = f[n][0]
            if f[n][3] == 0 and f[n][1] < up:
                up = f[n][1]
            if f[n][4] == 0 and f[n][0] < right:
                right = f[n][0]
            if f[n][5] == 0 and f[n][1] > down:
                down = f[n][1]
    if left <= right and down <= up:
        print("1 " + str(left) + " " + str(down))
    else:
        print(0)
