#!/usr/bin/python3
import math

# main
n, q = map(int, input().split())
b_size = math.ceil(math.sqrt(n))
b_len = math.ceil(n/b_size)
a = [2 ** 31 - 1 for i in range(n)]
b = [min(a[b_size * i:b_size * (i + 1)]) for i in range(b_len)]
for i in range(q):
    com, x, y = map(int, input().split())
    if com == 0:
        # update
        a[x] = y
        # update b
        index = x // b_size
        b[index] = min(a[index * b_size:(index + 1) * b_size])

    else:
        # find
        target = []
        x_index = x // b_size
        y_index = y // b_size
        x_mod = x % b_size
        y_mod = y % b_size
        if x_index == y_index:
            target.extend(a[x:y + 1])
        else:
            if x_mod == 0:
                target.append(b[x_index])
            else:
                target.extend(a[x:(x_index + 1) * b_size])

            if y_mod == b_size - 1:
                target.append(b[y_index])
            else:
                target.extend(a[y_index * b_size:y + 1])

            if x_index + 1 <= y_index - 1:
                target.append(min(b[x_index + 1 : y_index]))
        print(min(target))