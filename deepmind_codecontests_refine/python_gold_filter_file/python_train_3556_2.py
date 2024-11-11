import math


def main():
    n,m = map(int,input().split())
    grid = []
    for _ in range(n):
        x = [ch for ch in input()]
        grid.append(x)
    ans = 0
    for i in range(n):
        for j in range(m):
            if grid[i][j] == 'W':
                temp = 0
                try:
                    if grid[i][j + 1] == 'P' and j + 1 <= m - 1:
                        temp += 1
                except:
                    pass
                try:
                    if grid[i][j - 1] == 'P' and j - 1 >= 0:
                        temp += 1
                except:
                    pass
                try:
                    if grid[i + 1][j] == 'P' and i + 1 <= n - 1:
                        temp += 1
                except:
                    pass
                try:
                    if grid[i - 1][j] == 'P' and i - 1 >= 0:
                        temp += 1
                except:
                    pass
                if temp != 0:
                    ans += 1
    return ans





print(main())