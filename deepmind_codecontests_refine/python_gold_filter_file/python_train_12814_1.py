# import atexit
# import io
# import sys
#
# _INPUT_LINES = sys.stdin.read().splitlines()
# input = iter(_INPUT_LINES).__next__
# _OUTPUT_BUFFER = io.StringIO()
# sys.stdout = _OUTPUT_BUFFER
#
#
# @atexit.register
# def write():
#     sys.__stdout__.write(_OUTPUT_BUFFER.getvalue())


def main():
    n = int(input())

    str2 = list(input())
    str1 = list(input())

    if sorted(str1) != sorted(str2):
        print(-1)
        exit(0)

    res = []

    for i in range(n):
        if str1[i] == str2[i]:
            continue
        idx = str2[i:].index(str1[i]) + i

        while idx > i:
            str2[idx], str2[idx - 1] = str2[idx - 1], str2[idx]
            res.append(idx)
            idx -= 1

    if len(res) > 0:
        print(len(res))
        print(' '.join(map(str, res)))
    else:
        print(0)


if __name__ == "__main__":
    main()
