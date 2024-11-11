import sys
import math
import bisect

def solve(a, b, c):
    if c == 0:
        return b == a
    if c > 0:
        return b >= a and (b - a) % c == 0
    return b <= a and (a - b) % (-c) == 0

def main():
    a, b, c = map(int, input().split())
    if solve(a, b, c):
        print('YES')
    else:
        print('NO')

if __name__ == "__main__":
    main()
