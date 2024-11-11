import sys
import math
import bisect

def solve(n):
    for i in range(n // 7, -1, -1):
        if (n - 7 * i) % 4 == 0:
            cnt_4 = (n - 7 * i) // 4
            cnt_7 = i
            A = ['4'] * cnt_4 + ['7'] * cnt_7
            return ''.join(A)
    return -1

def main():
     n = int(input())
     ans = solve(n)
     print(ans)

if __name__ == "__main__":
    main()
