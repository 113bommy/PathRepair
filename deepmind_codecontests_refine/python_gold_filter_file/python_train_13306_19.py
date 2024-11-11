#!/usr/bin/env python3
import sys


def solve(L: int):
    tmp = L
    a = []
    while tmp > 0:
        a.append(tmp)
        tmp //= 2
    a.reverse()
    #print(a)
    e = []
    for i in range(1, len(a)):
        e.append([i, i + 1, 0])
        e.append([i, i + 1, a[i - 1]])
        if a[i] % 2 > 0:
            e.append([1, i + 1, a[i] - 1])
    print(len(a), len(e))
    for t in e:
        print(t[0], t[1], t[2])
    return


def main():
    def iterate_tokens():
        for line in sys.stdin:
            for word in line.split():
                yield word
    tokens = iterate_tokens()
    L = int(next(tokens))  # type: int
    solve(L)

if __name__ == '__main__':
    main()
