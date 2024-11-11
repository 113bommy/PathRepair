n = int(input())
rows = [list(map(int, input().split())) for x in range(n)]
columns = [[y[x] for y in rows] for x in range(n)]
d1 = [rows[x][x] for x in range(n)]
d2 = [rows[x][n - 1 - x] for x in range(n)]
condition = True
for x in rows:
    if 0 in x:
        try:
            if sum(x) != t:
                condition = False
                break
        except NameError:
            t = sum(x)
    else:
        try:
            if sum(x) != s:
                condition = False
                break
        except NameError:
            s = sum(x)
if condition:
    for x in columns:
        if 0 in x:
            if sum(x) != t:
                condition = False
                break
        elif sum(x) != s:
            condition = False
            break
if condition:
    if 0 in d1:
        if sum(d1) != t:
            condition = False
    elif sum(d1) != s:
        condition = False
    if 0 in d2:
        if sum(d2) != t:
            condition = False
    elif sum(d2) != s:
        condition = False
if condition:
    if n == 1:
        print(1)
    else:
        for x in rows:
            if 0 in x:
                a = x
            else:
                b = x
        c = sum(b) - sum(a)
        if c <= 0:
            print(-1)
        else:
            print(c)
else:
    print(-1)