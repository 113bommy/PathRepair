import sys
import math
import bisect
import itertools
import random
import re

def main():
    r, g, b = map(int, input().split())
    max_val = 0
    if r:
        val = ((r + 1) // 2 - 1) * 3 + 30
        max_val = max(max_val, val)
    if g:
        val = ((g + 1) // 2 - 1) * 3 + 1 + 30
        max_val = max(max_val, val)
    if b:
        val = ((b + 1) // 2 - 1) * 3 + 2 + 30
        max_val = max(max_val, val)
    print(max_val)

if __name__ == "__main__":
    main()
