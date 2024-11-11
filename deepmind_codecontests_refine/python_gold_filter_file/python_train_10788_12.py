import math as mt
import sys, string
from collections import Counter, defaultdict
input = sys.stdin.readline

# input functions
I = lambda : int(input())
M = lambda : map(int, input().split())
ARR = lambda: list(map(int, input().split()))

def printARR(arr):
    for e in arr:
        print(e, end=" ")
    print()

def main():
    n = I()
    l, r = 0, 0
    for _ in range(n):
        x, y = M()
        if x < 0:
            l += 1
        if x > 0:
            r += 1

    if l <= 1 or r <= 1:
        print("Yes")
    else:
        print("No") 


tc = 1
# tc = I()
for _ in range(tc):
    main()