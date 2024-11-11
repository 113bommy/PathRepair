import sys
import math
import bisect
import itertools
import random

def main():
    s = input()
    if len(set(list(s))) == 1:
        print(0)
    elif s == s[::-1]:
        print(len(s)-1)
    else:
        print(len(s))

if __name__ == "__main__":
    main()
