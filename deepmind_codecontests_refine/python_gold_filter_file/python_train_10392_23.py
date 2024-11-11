n = int(input())
XY = [list(map(int, input().split())) for _ in range(n)]
mod = sum(XY[0])%2
for x, y in XY:
    if mod != (x+y)%2:
        print(-1)
        exit()
m = 33-mod
print(m)
D = [2**i for i in range(31, -1, -1)]
if mod == 0:
    D.append(1)
print(" ".join(map(str, D)))
for x, y in XY:
    w = " "
    for d in D:
        if x-y >= 0 and x+y >= 0:
            w += "R"
            x -= d
        elif x-y < 0 and x+y >= 0:
            w += "U"
            y -= d
        elif x-y >= 0 and x+y < 0:
            w += "D"
            y += d
        else:
            w += "L"
            x += d
    print(w)