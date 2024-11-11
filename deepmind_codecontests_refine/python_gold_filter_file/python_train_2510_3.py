import math


def solve(n):
    if n < 1000:
        c = 0
        for i in range(1, n+1):
            if n % i == 0:
                c += 1
        return c
    else:
        c = 0
        for i in range(1, int(math.sqrt(n)) + 1):
            if n % i == 0:
                c += 1
                # print(i)
        if int(math.sqrt(n)) ** 2 == n:
            return 2*c-1
        else:
            return 2*c


b = int(input())
print(solve(b))