#!/usr/bin/env python3
'''
https://github.com/dhruvildave
http://codeforces.com/contest/1234/problem/B1
'''

from collections import deque


def soln() -> None:
    '''Driver code'''
    def logic() -> None:
        '''Logic'''
        n, k = [int(x) for x in input().split()]
        arr = [int(x) for x in input().split()]

        s = set()
        q = deque(maxlen=k)
        for i in arr:
            if i not in s:
                if len(q) == k:
                    s.remove(q[-1])
                q.appendleft(i)
                s.add(i)

        print(len(q))
        for i in q:
            print(i, end=' ')
        print()

    logic()


if __name__ == '__main__':
    soln()
