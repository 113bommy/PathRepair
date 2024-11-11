import io
import os
#input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline
import math

def main():
    n, t = map(int, input().split())
    first = math.inf
    first_index = -1
    for i in range(n):
        a, b = map(int, input().split())
        wait = math.ceil((t-a)/b)*b + a - t if t > a else a - t
        if wait < first:
            first = wait
            first_index = i

    print(first_index+1)


if __name__ == '__main__':
    main()
