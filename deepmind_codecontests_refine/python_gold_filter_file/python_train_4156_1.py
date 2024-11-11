dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]
N_MOVE = 4
EMPTY = 0
ROCK = 1
START = 2
GOAL = 3
 
INF = 100000
 
def in_field(field, x, y):
    return y >=0 and y < len(field) and x >= 0 and x< len(field[0])
 
 
def move_to_rock(field, x, y, direction):
    while(True):
        x += dx[direction]
        y += dy[direction]
        if not in_field(field, x, y):
            return None
        elif field[y][x] == ROCK:
            x -= dx[direction]
            y -= dy[direction]
            break
        elif field[y][x] == GOAL:
            break
    return x, y
 
 
def dfs(depth, field, x, y):
    if depth > 10:
        return None
 
    cost = INF
    for r in range(N_MOVE):
        if cost <= depth:
            return cost
        nx, ny = x + dx[r], y + dy[r]
        if not in_field(field, nx, ny):
            continue
        if field[ny][nx] == ROCK:
            continue
        next_pos = move_to_rock(field, x, y, r)
        if next_pos is None:
            continue
        nx, ny = next_pos
        if field[ny][nx] == GOAL:
            return depth
        rock_pos_x, rock_pos_y = nx+dx[r], ny+dy[r]
        assert field[rock_pos_y][rock_pos_x] == ROCK
        field[rock_pos_y][rock_pos_x] = EMPTY
        result = dfs(depth+1, field, nx, ny)
        if result is not None:
            cost = min(cost, result)
        field[rock_pos_y][rock_pos_x] = ROCK
    return cost
 
 
def find_start_pos(field):
    h = len(field)
    w = len(field[0])
    for y in range(h):
        for x in range(w):
            if field[y][x] == START:
                return x, y
    return None  # ?
 
 
def solve():
    w, h = map(int, input().split())
    if w == 0 or h == 0:
        return None
    field = []
    for y in range(h):
        field.append(list(map(int, input().split())))
    x, y = find_start_pos(field)
    res = dfs(1, field, x, y)
    return res
 
 
if __name__ == '__main__':
    while(True):
        answer = solve()
        if answer is None:
            break
        elif answer == INF:
            print(-1)
        else:
            print(answer)
