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
    a, b, c = sorted(list(map(int, input().split())))

    res = 9999999999999

    for i in range(a, c + 1):
        for j in range(b, c + 1):
            if i + j > c and i + c > j and j + c > i:
                res = min(res, i + j - a - b)
                break
    print(res)


if __name__ == "__main__":
    main()
