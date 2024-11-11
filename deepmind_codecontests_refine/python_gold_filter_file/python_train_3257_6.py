from collections import defaultdict
from math import ceil


def main(n, W, w):
    """Checks if we can pick items to fill the knapsack
    at least by half its size."""
    target = ceil(W/2)
    sorted_list = sorted(enumerate(w, 1), key=lambda x: x[1])
    # print(sorted_list)
    count = 0
    for i, x in enumerate(sorted_list, 1):
        # print(x)
        if x[1] > W:
            pass
        elif x[1] >= target:
            return 1, [x[0]]
        else:
            count += x[1]
            if count > W:
                count = 0
            elif count >= target:
                return i, [z[0] for z in sorted_list[:i]]

    return -1, []

# Main
t = int(input())
for i in range(1, t + 1):
    n, W = [int(s) for s in input().split(" ")]
    w = [int(s) for s in input().split(" ")]

    status, li = main(n, W, w)
    if status == -1:
        print(-1)
    else:
        print(status)
        print(*li)
