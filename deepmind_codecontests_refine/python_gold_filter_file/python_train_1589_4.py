from sys import stdin, stdout
from types import FunctionType
# import math
# import re
# import itertools
# import collections
# import statistics
# import calendar
# import datetime
# import operator


# a mod b = c
# is basically
# a = nb + c

t = int(input())
for _ in range(t):
    x, y, n = map(int, input().split())
    for i in range((n//x), -1, -1):
        k = (x*i) + y
        if -1 < k <= n:
            print(k)
            break