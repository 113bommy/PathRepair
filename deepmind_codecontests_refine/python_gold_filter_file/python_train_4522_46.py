from itertools import accumulate as ac
from collections import Counter as cc
from bisect import bisect_left as bsl
from bisect import bisect as bs
from math import factorial as f
from collections import *
from itertools import *
from string import *
from bisect import *
from queue import *
from heapq import *
from math import *
from sys import *
from re import *
def fast(): return stdin.readline().strip()
def zzz(): return [int(i) for i in fast().split()]


z, zz = input, lambda: list(map(int, z().split()))
szz, graph, mod, szzz = lambda: sorted(
    zz()), {}, 10**9+7, lambda: sorted(zzz())


def lcd(xnum1, xnum2): return (xnum1*xnum2//gcd(xnum1, xnum2))
def output(answer): stdout.write(str(answer))


###########################---Test-Case---#################################
"""

  If you Know me , Then you probably don't know me !


"""
###########################---START-CODING---##############################

WIDTH = 600


RED = (255, 0, 0)
GREEN = (0, 255, 0)
BLUE = (0, 255, 0)
YELLOW = (255, 255, 0)
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)
PURPLE = (128, 0, 128)
ORANGE = (255, 165, 0)
GREY = (128, 128, 128)
TURQUOISE = (64, 224, 208)


class Spot:
    def __init__(self, row, col, width, total_rows):
        self.row = row
        self.col = col
        self.x = row * width
        self.y = col * width
        self.color = WHITE
        self.neighbors = []
        self.width = width
        self.total_rows = total_rows

    def get_pos(self):
        return self.row, self.col

    def is_closed(self):
        return self.color == RED

    def is_open(self):
        return self.color == GREEN

    def is_barrier(self):
        return self.color == BLACK

    def is_start(self):
        return self.color == ORANGE

    def is_end(self):
        return self.color == TURQUOISE

    def reset(self):
        self.color = WHITE

    def make_start(self):
        self.color = ORANGE

    def make_closed(self):
        self.color = RED

    def make_open(self):
        self.color = GREEN

    def make_barrier(self):
        self.color = BLACK

    def make_end(self):
        self.color = TURQUOISE

    def make_path(self):
        self.color = PURPLE

    def update_neighbors(self, grid):
        self.neighbors = []
        # DOWN
        if self.row < self.total_rows - 1:
            self.neighbors.append(grid[self.row + 1][self.col])

        if self.row > 0:  # UP
            self.neighbors.append(grid[self.row - 1][self.col])

        # DR
        if self.row < self.total_rows - 1 and self.col < self.total_rows - 1:
            self.neighbors.append(grid[self.row + 1][self.col+1])

        # UL

        if self.row > 0 and self.col > 0:
            self.neighbors.append(grid[self.row-1][self.col - 1])

        # UR

        if self.row > 0 and self.col < self.total_rows - 1:
            self.neighbors.append(grid[self.row-1][self.col+1])
        # DL
        if self.row < self.total_rows - 1 and self.col > 0:
            self.neighbors.append(grid[self.row+1][self.col-1])

        # RIGHT
        if self.col < self.total_rows - 1:
            self.neighbors.append(grid[self.row][self.col + 1])

        if self.col > 0:  # LEFT
            self.neighbors.append(grid[self.row][self.col - 1])

    def __lt__(self, other):
        return False


def h(p1, p2):
    x1, y1 = p1
    x2, y2 = p2
    return abs(x1 - x2) + abs(y1 - y2)


def reconstruct_path(came_from, current):
    lst = []
    while current in came_from:
        current = came_from[current]
        current.make_path()
        lst.append(current.get_pos())
    return lst


def algorithm(grid, start, end):
    count = 0
    open_set = PriorityQueue()
    open_set.put((0, count, start))
    came_from = {}
    g_score = {spot: float("inf") for row in grid for spot in row}
    g_score[start] = 0
    f_score = {spot: float("inf") for row in grid for spot in row}
    f_score[start] = h(start.get_pos(), end.get_pos())

    open_set_hash = {start}

    while not open_set.empty():
        current = open_set.get()[2]
        open_set_hash.remove(current)

        if current == end:
            lst = reconstruct_path(came_from, end)
            end.make_end()

            return lst
        for neighbor in current.neighbors:
            temp_g_score = g_score[current] + 1

            if temp_g_score < g_score[neighbor]:
                came_from[neighbor] = current
                g_score[neighbor] = temp_g_score
                f_score[neighbor] = temp_g_score + \
                    h(neighbor.get_pos(), end.get_pos())
                if neighbor not in open_set_hash:
                    count += 1
                    open_set.put((f_score[neighbor], count, neighbor))
                    open_set_hash.add(neighbor)
                    neighbor.make_open()

        if current != start:

            current.make_closed()

    return False


def make_grid(rows, width):
    grid = []
    gap = width // rows
    for i in range(rows):
        grid.append([])
        for j in range(rows):
            spot = Spot(i, j, gap, rows)
            grid[i].append(spot)

    return grid


ROWS = 8
grid = make_grid(ROWS, WIDTH)


one = fast()
spot = grid[ord(one[0])-97][int(one[1])-1]
start = spot
start.make_start()


two = fast()
spot = grid[ord(two[0])-97][int(two[1])-1]
end = spot
end.make_end()

for row in grid:
    for spot in row:
        spot.update_neighbors(grid)
res = algorithm(grid, start, end)[::-1]


prev = start.get_pos()
print(len(res))
res= res+ [end.get_pos()]
for i in range(len(res)):
    i = res[i]
    if i[0] > prev[0] and i[1] > prev[1]:
        print("RU")
    elif i[0] < prev[0] and i[1] < prev[1]:
        print("LD")
    elif i[0] > prev[0] and i[1] == prev[1]:
        print("R")
    elif i[0] < prev[0] and i[1] == prev[1]:
        print("L")
    elif i[0] == prev[0] and i[1] > prev[1]:
        print("U")
    elif i[0] == prev[0] and i[1] < prev[1]:
        print("D")
    elif i[0] > prev[0] and i[1] < prev[1]:
        print("RD")
    elif i[0] < prev[0] and i[1] > prev[1]:
        print("LU")
    prev = i
