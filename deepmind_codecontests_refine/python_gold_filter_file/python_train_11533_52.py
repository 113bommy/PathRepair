def main():
    from collections import deque

    h, w = map(int, input().split())
    start = tuple(map(lambda x: int(x) - 1, input().split()))
    goal = tuple(map(lambda x: int(x) - 1, input().split()))

    maze = tuple([tuple(input()) for _ in range(h)])
    vis = [[False] * w for _ in range(h)]

    mw = [(1, 0), (0, 1), (-1, 0), (0, -1)]
    mj = list(set((i, j) for i in range(-2, 3) for j in range(-2, 3)) - set(mw) - {(0, 0)})

    q = deque()
    q.append((start[0], start[1], 0))
    while q:
        y, x, c = q.popleft()
        if not (0 <= y < h and 0 <= x < w) or vis[y][x] or maze[y][x] == '#':
            continue
        vis[y][x] = True
        if (y, x) == goal:
            print(c)
            break
        for a, b in mw:
            q.appendleft((y + a, x + b, c))
        for a, b in mj:
            q.append((y + a, x + b, c + 1))
    else:
        print(-1)


if __name__ == '__main__':
    main()
