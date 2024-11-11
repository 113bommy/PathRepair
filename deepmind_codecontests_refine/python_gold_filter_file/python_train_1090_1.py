h, n = map(int, input().split())

total = 2 ** (h + 1) - 1

sum_v = 0
range_v = (0, 2 ** h - 1)
prev_r = range_v
x = n - 1
left = False
curr_h = 0


def in_range(r, x):
    return r[0] <= x <= r[1]


def range_width(r):
    return r[1] - r[0] + 1


def update_range(r, l):
    w = range_width(r) // 2
    st = r[0] if l else r[0] + w
    return st, st + w - 1

#print("X ", x)
while range_width(range_v) != 0:
    left = not left
    #print(range_v)

    tmp = range_v
    if in_range(range_v, x):
        range_v = update_range(range_v, left)
        sum_v += 1
        curr_h += 1
        #print("+ 1")
    else:
        range_v = update_range(prev_r, left)
        sum_v += 2 ** (h - curr_h + 1) - 1
        #print("+ ", 2 ** (h - curr_h + 1) - 1)

    prev_r = tmp

print(sum_v - 1)