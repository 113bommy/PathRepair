#!/usr/bin/env python3
import sys

def main():
    m, b = map(int, sys.stdin.readline().split())
    results = []
    for _x in range(0, b+1):
        x = m * _x
        y = b - _x
        results.append(rectangle_bananas(x, y))
    print(max(results))

def rectangle_bananas(x, y):
    return ((x+1) * (y+1) * (x+y)) // 2

if __name__ == '__main__':
    main()
