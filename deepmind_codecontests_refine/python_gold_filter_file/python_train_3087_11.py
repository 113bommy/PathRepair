import sys
import math
import bisect
import itertools

def main():
    n = int(input())
    A = []
    for c in input():
        A.append(c)
        if len(A) >= 2 and A[-2] in 'aeiouy' and A[-1] in 'aeiouy':
            A.pop()
    print(''.join(A))

if __name__ == "__main__":
    main()
