import sys
from collections import Counter
from bisect import bisect_left, bisect_right

def input():
    return sys.stdin.readline().strip()

def dinput():
    return int(input())

def tinput():
    return input().split()

def rinput():
    return map(int, tinput())

def rtinput():
    return map(float, tinput())

def rec(left, right, q, d, f):
    x = bisect_right(q, right) - bisect_left(q, left)
    if x == 0:
        return d
    
    if left == right:
        if x == 0:
            return d
        else:
            return f * x
    
    z = (left + right) >> 1
    w, e = rec(left, z, q, d, f), rec(z + 1, right, q, d, f)

    return min(f * x * (right - left + 1), w + e)

def main():
    a, s, d, f = rinput()
    q = sorted(rinput())
    print(rec(1, 2 ** a, q, d, f))
main()