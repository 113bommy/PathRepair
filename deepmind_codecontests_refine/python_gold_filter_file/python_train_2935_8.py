import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline


def solve():
    N = int(input())
    grid = [[None]*N for _ in range(N)]

    grid[0][0] = "B"
    Q = [[0, 0, "B"]]

    DX = [-2, -1, 1, 2, 2, 1, -1, 2]
    DY = [1, 2, 2, 1, -1, -2, -2, -1]
    while Q:
        tmp = []
        for x, y, color in Q:
            for dx, dy in zip(DX, DY):
                nx = x+dx
                ny = y+dy
                if 0 <= nx < N and 0 <= ny < N:
                    if grid[nx][ny] is None:
                        new_col = "W" if color == "B" else "B"
                        grid[nx][ny] = new_col
                        tmp.append([nx, ny, new_col])
        Q = tmp
    ans = ""
    for row in range(N):
        for col in range(N):
            if grid[row][col] is None:
                grid[row][col] = "B"
    for v in grid:
        ans += "".join(v)+"\n"
    print(ans)


def solve2():
    N = int(input())
    grid = [["B"]*N for _ in range(N)]

    for row in range(N):
        for col in range(N):
            if (row+col) % 2 == 1:
                grid[row][col] = "W"
    ans = ""
    for v in grid:
        ans += "".join(v)+"\n"
    print(ans)


solve2()
