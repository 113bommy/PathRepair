import sys
import math
import bisect
import itertools
import random

def is_leap_year(y):
    if y % 400 == 0:
        return True
    if y % 100 == 0:
        return False
    return y % 4 == 0

def month_days(y, m):
    if m == 2:
        if is_leap_year(y):
            return 29
        else:
            return 28
    elif m <= 7 and m % 2 == 1:
        return 31
    elif m <= 7 and m % 2 == 0:
        return 30
    elif m >= 8 and m % 2 == 1:
        return 30
    elif m >= 8 and m % 2 == 0:
        return 31
    return -1

def main():
    A = input().split()
    if A[2] == 'week':
        x = int(A[0])
        ans = 0
        t = 5
        for i in range(366):
            if t == x:
                ans += 1
            t = (t + 1)
            if t == 8:
                t = 1
        print(ans)
    elif A[2] == 'month':
        x = int(A[0])
        ans = 0
        for i in range(1, 13):
            if month_days(2016, i) >= x:
                ans += 1
        print(ans)

if __name__ == "__main__":
    main()
