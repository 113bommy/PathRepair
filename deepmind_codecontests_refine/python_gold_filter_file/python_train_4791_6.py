import math


def make_row(id, heap):
    s = "node " + str(id) + ": key = " + str(heap[id - 1]) + ", "
    length = len(heap)
    if 0 <= math.floor(id // 2) - 1 < length:
        s += "parent key = " + str(heap[math.floor(id // 2) - 1]) + ", "
    if 0 <= 2 * id - 1 < length:
        s += "left key = " + str(heap[2 * id - 1]) + ", "
    if 0 <= 2 * id < length:
        s += "right key = " + str(heap[2 * id]) + ", "
    return s


h = int(input())
heap = [int(x) for x in input().split()]

for id in range(1, h + 1):
    print(make_row(id, heap))
