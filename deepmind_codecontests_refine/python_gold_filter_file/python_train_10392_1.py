n = int(input())
xy = []
flag = "f"
for i in range(0,n):
    X,Y = map(int,input().split())
    xy.append((X,Y))
    if i == 0:
        m = (X+Y)%2
    if m != (X+Y)%2:
        flag = "t"
if flag == "t":
    print(-1)
    exit()

d = [2**i for i in range(31,-1,-1)]

if m == 0:
    d.append(1)

print(len(d))
for i in range(0,len(d)):
    print(d[i],end = " ")
print()
for i in range(0,n):
    x,y = xy[i]
    w = ""
    for j in range(0,len(d)):
        if y <= x and  y >= -x:
            w += "R"
            x -= d[j]
        elif y >= x and y >= -x:
            w += "U"
            y -= d[j]
        elif y > x and y < -x:
            w += "L"
            x += d[j]
        else:
            w += "D"
            y += d[j]
    print(w)
