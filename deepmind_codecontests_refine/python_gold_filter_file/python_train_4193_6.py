#----------Input functions-------------
import sys
input = sys.stdin.readline
def inInt():
    return int(input())
def inStr():
    return input().strip("\n")
def inIList():
    return(list(map(int,input().split())))
def inSList():
    return(input().split())

def solve(rows, cols, grid):
    #----solution here----
    top = grid[-1]
    counter = 0
    for c in range(cols-1):
        if top[c] == 'D':
            counter += 1
    for r in range(rows - 1):
        if grid[r][-1] == 'R':
            counter += 1
    print(counter)

tests = inInt()
for case in range(tests):
    # ------take input here------
    dim = inIList()
    rows = dim[0]
    cols = dim[1]
    grid = []
    for r in range(rows):
        grid.append(inStr())
    solve(rows, cols, grid)