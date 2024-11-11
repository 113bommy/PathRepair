import collections


def main():
    h, w = map(int, input().split())
    grid = [[None for _ in range(w)] for _ in range(h)]
    # print(grid)
    r = map(int, input().split())
    c = map(int, input().split())
    for i, v in enumerate(r):
        for j in range(v):
            grid[i][j] = 1
        if v < w:
            grid[i][v] = 0
    for i, v in enumerate(c):
        for j in range(v):
            if grid[j][i] == 0:
                print(0)
                return
            grid[j][i] = 1
        if v < h:
            if grid[v][i] == 1:
                print(0)
                return
            grid[v][i] = 0
    flex = sum([g.count(None) for g in grid])
    if flex == 0:
        print(1)
        return
    ans = 1
    for i in range(flex):
        ans = (ans * 2) % 1000000007
    print(ans)
    return


if __name__ == '__main__':
    main()
