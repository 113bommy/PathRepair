from bisect import bisect_left as lower_bound, bisect_right as upper_bound
from sys import stdin, stdout
from collections import defaultdict
from math import log10


def solve(num, k, seen):
    max_power = int(log10(num)/log10(k)) + 3

    for i in range(max_power, -1, -1):
        if k**i <= num:
            if seen[i]: return False

            num -= k**i
            seen[i] = True

    return (num == 0)

def main():
    t = int(input())

    for _ in range(t):
        n, k = list(map(int, input().strip().split()))
        arr = list(map(int, input().strip().split()))
        
        a = []
        for num in arr:
            if num: a.append(num)

        a.sort()
        seen = [False for _ in range(64)]

        f = False

        for num in a:
            if not solve(num, k, seen):
                f = True
                break

        if f: print("NO")
        else: print("YES")

if __name__ == "__main__": main()
