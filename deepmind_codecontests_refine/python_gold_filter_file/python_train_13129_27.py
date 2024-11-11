#E55_A

import sys

t = int(input())

for i in range(0, t):
    ln = [int(j) for j in sys.stdin.readline().rstrip().split(" ")]
    n = ln[0]
    x = ln[1]
    y = ln[2]
    d = ln[3]
    num = -1
    if x % d == y % d:
        num = abs(x - y) // d
    elif y == 1:
        num = (x - 2) // d + 1
    else:
        num1 = (x - 2) // d + 1
        num2 = (n - x - 1) // d + 1
        mnum = 1000000000
        om = mnum
        if 1 % d == y % d:
            mnum = num1 +  (y - 1) // d
        if n % d == y % d:
            mnum = min(mnum, num2 + (n - y) // d)
        if mnum != om:
            num = mnum
    print(num)
