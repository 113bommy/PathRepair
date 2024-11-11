import os
import sys
from functools import lru_cache, reduce
from io import BytesIO

sys.setrecursionlimit(30000)

input = BytesIO(os.read(0, os.fstat(0).st_size)).readline
print = lambda x: os.write(1, str(x).encode())


def main():
    init_w = int(input())
    cnt = [int(i) for i in input().split()]

    dp_cnt = [min(cnt_i, 16) for i, cnt_i in enumerate(cnt)]
    greedy_cnt = [cnt_i - dp_cnt_i for cnt_i, dp_cnt_i in zip(cnt, dp_cnt)]

    i, w = 8, init_w
    while (i > 0) and (w > 0):
        w -= i * greedy_cnt[i - 1]
        if w < 0:
            w %= i
            for j in range(2):
                w += i if min(greedy_cnt[i - 1], dp_cnt[i - 1]) > j + 1 else 0

        i -= 1

    weights = reduce(list.__add__, (dp_cnt_i * [i + 1] for i, dp_cnt_i in enumerate(dp_cnt)))

    @lru_cache(maxsize=None)
    def solve(i, val):
        if val == 0:
            return True
        if i == 0:
            return False
        return solve(i - 1, val) or solve(i - 1, val - weights[i - 1])

    for val in range(min(w, sum(weights)), -1, -1):
        if solve(len(weights), val):
            print(init_w - w + val)
            break


if __name__ == '__main__':
    main()
