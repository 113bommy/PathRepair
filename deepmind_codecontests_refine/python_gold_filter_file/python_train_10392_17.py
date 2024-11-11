N = int(input())
XY = [list(map(int,input().split())) for _ in range(N)]

num_type = sum(XY[0])%2 
for xy in XY:
    if(sum(xy)%2 != num_type):
        print(-1)
        break
else:
    m = 40-num_type
    print(m)
    D = [2**i for i in range(38,-1,-1)]
    if not(num_type):
        D.append(1)

    print(' '.join(map(str,D)))
    for xy in XY:
        p = xy
        w = ""
        for i in range(m):
            if 0<=p[0]-p[1] and 0<=p[0]+p[1]:
                w += "R"
                p[0] -= D[i]
            elif 0>p[0]-p[1] and 0<=p[0]+p[1]:
                w += "U"
                p[1] -= D[i]
            elif 0<=p[0]-p[1] and 0>p[0]+p[1]:
                w += "D"
                p[1] += D[i]
            else:
                w += "L"
                p[0] += D[i]
        print(w)
