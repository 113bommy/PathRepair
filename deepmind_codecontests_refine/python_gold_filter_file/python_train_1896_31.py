import sys
import math
import re
import io

def solve2(n, k):
    n += k
    if n >= 21 and (n - 21) % 14 == 0:
        return True
    return False

def solve(n):
    for i in range(1, 7):
        if solve2(n, i):
            return True
    return False

def main():
    n = int(input())
    A = list(map(int, input().split()))
    for a in A:
        if solve(a):
            print('YES')
        else:
            print('NO')

if __name__ == "__main__":
    main()
