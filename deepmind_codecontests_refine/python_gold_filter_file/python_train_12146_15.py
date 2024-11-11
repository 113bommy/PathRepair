def bad():
    print('NO')
    exit()


def OK(a, b):
    return (0 <= a < n) and (0 <= b < m)


def get_neig(a, b):
    return [(a + dx[i], b + dy[i]) for i in range(8) if OK(a + dx[i], b + dy[i])]


n, m = map(int, input().split())
field = [input() for i in range(n)]

dx = (+1, +1, 0, -1, -1, -1, 0, +1)
dy = (0, +1, +1, +1, 0, -1, -1, -1)

for x in range(n):
    for y in range(m):
        if field[x][y] == '.':
            for el in get_neig(x, y):
                x_, y_ = el
                
                if field[x_][y_] == '*':
                    bad()
        
        elif field[x][y] != '*':
            to_do = int(field[x][y])
            c = 0
            
            for el in get_neig(x, y):
                x_, y_ = el
                
                if field[x_][y_] == '*':
                    c += 1
                
            if c != to_do:
                bad()

print('YES')