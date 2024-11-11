# -*- coding: utf-8 -*-
import sys
# from operator import itemgetter
# from fractions import gcd
# from math import ceil, floor
# from copy import deepcopy
# from itertools import accumulate
from collections import deque
# import math
# from functools import reduce
input = sys.stdin.readline
def ii(): return int(input())
def mi(): return map(int, input().rstrip().split())
def lmi(): return list(map(int, input().rstrip().split()))
def li(): return list(input().rstrip())
# template

# BEGIN CUT HERE


class Graph():

    def __init__(self, n, Weighted=False, Directed=True, Matrix=False):
        self.sz = n
        self.is_Weighted = Weighted
        self.is_Directed = Directed
        self.is_Matrix = Matrix
        if Matrix:
            if Weighted:
                self.graph = [[0 for _i in range(n)] for _j in range(n)]
            else:
                self.graph = [[0 for _i in range(n)] for _j in range(n)]
        else:
            self.graph = [[] for _i in range(n)]

    def _weighted_add_edge(self, x, y, w):
        if self.is_Matrix:
            self.graph[x][y] = w
        else:
            self.graph[x].append((y, w))

    def _unweighted_add_edge(self, x, y):
        if self.is_Matrix:
            self.graph[x][y] = 1
        else:
            self.graph[x].append(y)

    def add_edge(self, x, y, *w):
        if self.is_Directed:
            if self.is_Weighted:
                self._weighted_add_edge(x, y, w[0])
            else:
                self._unweighted_add_edge(x, y)
        else:
            if self.is_Weighted:
                self._weighted_add_edge(x, y, w[0])
                self._weighted_add_edge(y, x, w[0])
            else:
                self._unweighted_add_edge(x, y)
                self._unweighted_add_edge(y, x)

    def _convert_to_maxrix(self):
        if self.is_Matrix:
            return self
        mat_g = self.__class__(
            self.sz, Weighted=self.is_Weighted, Directed=self.is_Directed, Matrix=True)
        if self.is_Weighted:
            for i in range(self.sz):
                for j in self.graph[i]:
                    mat_g.add_edge(i, j[0], j[1])
        else:
            for i in range(self.sz):
                for j in self.graph[i]:
                    mat_g.add_edge(i, j)
        return mat_g

    def __getitem__(self, n):
        return self.graph[n]

    # def __setitem__(self, n, v):
    #     if not self.is_Weighted and not self.is_Matrix:
    #         self.graph[n] = v

    def __str__(self):
        return str([self.graph[i] for i in range(self.sz)])


def main():
    n = ii()
    g = Graph(n, Directed=False)
    for i in range(n - 1):
        s, t = mi()
        g.add_edge(s-1, t-1)
    for i in range(n):
        if len(g[i]) == 2:
            break
    else:
        print('YES')
        sys.exit()
    print('NO')


if __name__ == '__main__':
    main()
