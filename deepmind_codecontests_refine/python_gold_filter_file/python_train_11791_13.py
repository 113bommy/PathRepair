import sys
import heapq
import random
import collections
import bisect

# available on Google, not available on Codeforces
# import numpy as np
# import scipy
# from scipy.stats import binom


def solve(a):
    # console("----- solving ------")

    lst = []
    base = []

    for i in range(1,40):
        for j in range(10):
            base.append((i,j))
            res = 1
            for k in range(10):
                if j > k:
                    res *= i + 1
                else:
                    res *= i
            lst.append(res)
            

    a,b = base[bisect.bisect_left(lst,a)]

    # print(a,b)
    # print(lst[:20])

    res = ""
    for c,j in zip("codeforces", range(10)):
        if j < b:
            res += c*(a+1)
        else:
            res += c*a
    
    return res


def console(*args):  # the judge will not read these print statement
    print('\033[36m', *args, '\033[0m', file=sys.stderr)


# for case_num in range(int(input())):
    # read line as a string
    # strr = input()

    # read line as an integer
k = int(input())
    
    # read one line and parse each word as a string
    # lst = input().split()

    # read one line and parse each word as an integer
    # a,b,c = list(map(int,input().split()))

    # read matrix and parse as integers (after reading read nrows)
    # lst = list(map(int,input().split()))
    # nrows = lst[0]  # index containing information, please change
    # grid = []
    # for _ in range(nrows):
    #     grid.append(list(map(int,input().split())))

res = solve(k)  # please change
    
    # Google - case number required
    # print("Case #{}: {}".format(case_num+1, res))

    # Codeforces - no case number required
print(res)


