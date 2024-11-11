# Carrot Cakes
# https://codeforces.com/contest/799/problem/A
#
# Author: eloyhz
# Date: Aug/26/2020

import math

if __name__ == '__main__':
    n, t, k, d = [int(x) for x in input().split()]
    if k >= n:
        print('NO')
    else:
        r1 = math.ceil(n / k) * t
        r2 = d + math.ceil((n - d // t * k) / (2 * k)) * t
        if r2 < r1:
            print('YES')
        else:
            print('NO')

