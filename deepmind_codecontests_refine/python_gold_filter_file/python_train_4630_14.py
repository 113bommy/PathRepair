n = int(input())
x = list(map(int, input().split()))

if x.count(1) == 0 or x.count(2) == 0 or x.count(3) == 0:
    print(0)
else:
    teams = 0
    y = []
    while x.count(1) != 0 and x.count(2) != 0 and x.count(3) != 0:
        y.append(x.index(1)+1)
        x[x.index(1)] = 0
        y.append(x.index(2)+1)
        x[x.index(2)] = 0
        y.append(x.index(3)+1)
        x[x.index(3)] = 0
        teams += 1
    print(teams)
    i = 0
    while i < len(y)-2:
        print(y[i], y[i+1], y[i+2])
        i += 3