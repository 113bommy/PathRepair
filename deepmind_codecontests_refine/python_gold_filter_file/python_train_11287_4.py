def main(inp):
    n = int(input())
    arr = split_inp_int(inp)
    arr.sort()

    if n == 1:
        print(-1)
        return
    if n == 2:
        a, b = arr
        diff = b-a
        if diff == 0:
            print(1)
            print(a)
        elif diff % 2 == 0:
            print(3)
            print(a-diff, a+diff//2,  b+diff)
        else:
            print(2)
            print(a-diff, b+diff)
        return

    diffs = [arr[i]-arr[i-1] for i in range(1, n)]
    if len(set(diffs)) > 2:
        print(0)
        return
    if len(set(diffs)) == 1:
        diff = arr[1]-arr[0]
        if diff == 0:
            print(1)
            print(arr[0])
        else:
            print(2)
            print(arr[0]-diff, arr[-1]+diff)
        return

    diffs_counter = [(k, v) for k, v in Counter(diffs).items()]
    # print(diffs_counter)
    diffs_counter.sort()
    if diffs_counter[1][1] != 1:
        print(0)
        return
    common_diff = diffs_counter[0][0]
    other_diff = diffs_counter[1][0]
    if other_diff != common_diff*2:
        print(0)
        return
    print(1)
    print(arr[0] + common_diff*diffs.index(other_diff) + common_diff)


def split_inp_int(inp):
    return list(map(int, inp().split()))


def use_fast_io():
    import sys

    class InputStorage:
        def __init__(self, lines):
            lines.reverse()
            self.lines = lines

        def input_func(self):
            if self.lines:
                return self.lines.pop()
            else:
                return ""

    return input
    input_storage_obj = InputStorage(sys.stdin.readlines())
    return input_storage_obj


from collections import Counter, defaultdict
from functools import reduce
import operator
import math


def product(arr_):
    return reduce(operator.mul, arr_, 1)

if __name__ == "__main__":

    main(use_fast_io())
