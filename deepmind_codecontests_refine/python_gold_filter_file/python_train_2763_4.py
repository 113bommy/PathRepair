"""
Codeforces Round #361 (Div. 2)

Problem 689 A. Mike and Cellphone

@author yamaton
@date 2016-07-09
"""

import itertools as it
import functools
import operator
import collections
import math
import sys


def solve(s):
    if '0' in s:
        tf = any(i in s for i in '123')
    elif all(i not in s for i in '79'):
        tf = False
    else:
        tf = (any(i in s for i in '147') and 
              any(i in s for i in '369') and
              any(i in s for i in '123') and
              any(i in s for i in '789'))
    return tf_to_yn(tf)


def pp(*args, **kwargs):
    return print(*args, file=sys.stderr, **kwargs)

def tf_to_yn(tf):
    return 'YES' if tf else 'NO'


def main():
    n = int(input())
    s = input().strip()
    assert len(s) == n
    result = solve(s)
    print(result)


if __name__ == '__main__':
    main()
