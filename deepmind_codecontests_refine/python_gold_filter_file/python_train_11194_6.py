n, y, x = list(map(int, input().split()))
a, b = [0, 0]
direct = 1
field = [[0 for j in range(x)] for i in range(y)]
if x * y >= n:
    for i in range(1, n + 1):
        field[b][a] = i
        if direct == 1:
            if a + direct < x and field[b][a + direct] == 0:
                a += direct
            elif b + direct < y and field[b + direct][a] == 0:
                b += direct
            else:
                direct = -1
                a += direct
        else:
            if a + direct >= 0 and field[b][a + direct] == 0:
                a += direct
            elif b + direct >= 0 and field[b + direct][a] == 0:
                b += direct
            else:
                direct = 1
                a += direct
    for i in range(y):
        print(*field[i])
else:
    print(-1)