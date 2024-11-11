N = int(input())
XY = [list(map(int, input().split(" "))) for _ in range(N)]
parity = (XY[0][0] + XY[0][1]) % 2
maxXY = 0
for x, y in XY:
    if (x + y) % 2 != parity:
        print("-1")
        exit()
    maxXY = max(x+y, maxXY)
arm = [1, 1, ]
if parity == 1:
    arm[1] = 2

tmp = arm[1]
m = 2

for _ in range(40):
    tmp *= 2
    m += 1
    arm.append(tmp)
    if tmp > maxXY:
        break
print(m)
print(" ".join(map(str, arm)))
armR = arm[::-1]
for x, y in XY:
    nowX, nowY = [x, y]
    ansR = ""
    for l in armR:
        if abs(nowX) >= abs(nowY):
            if nowX >= 0:
                nowX -= l
                ansR += "R"
            else:
                nowX += l
                ansR += "L"
        else:
            if nowY >= 0:
                nowY -= l
                ansR += "U"
            else:
                nowY += l
                ansR += "D"
    print(ansR[::-1])

