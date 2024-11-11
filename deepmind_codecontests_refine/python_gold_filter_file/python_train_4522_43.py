from collections import deque

directions = {
    'D': (1, 0),
    'U': (-1, 0),
    'R': (0, 1),
    'L': (0, -1),
    'RD': (1, 1),
    'RU': (-1, 1),
    'LD': (1, -1),
    'LU': (-1, -1)
}

def code(i, j):
    return i * 8 + j

def decode(x):
    return (x // 8, x % 8)

def code_input():
    coord = input();
    j = ord(coord[0]) - ord('a')
    i = 8 - int(coord[1])
    return code(i, j)

def move(x, d):
    (i, j) = decode(x)
    (di, dj) = directions[d]
    i += di
    j += dj
    if i >= 0 and i < 8 and j >= 0 and j < 8:
        return code(i,j)
    else:
        return -1

s = code_input()
t = code_input();

q = deque([])
q.append(s)
visited = set([s])
last_dir = {}
prev_field = {}
dist = {s: 0}

while len(q) > 0 and t not in visited:
    field = q.popleft()
    for d in directions:
        neighbor = move(field, d)
        if neighbor != -1 and neighbor not in visited:
            visited.add(neighbor)
            q.append(neighbor)
            dist[neighbor] = dist[field] + 1
            last_dir[neighbor] = d
            prev_field[neighbor] = field
print(dist[t])

field = t
path = deque([])
while field in prev_field:
    path.appendleft(last_dir[field])
    field = prev_field[field]
for mv in path:
    print(mv)