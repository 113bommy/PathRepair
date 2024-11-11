#!/usr/bin/env python
# -*- coding: utf-8 -*-
import sys

sys.setrecursionlimit(210000)


class Node(object):

  def __init__(self, idx, color):
    self.idx = idx
    self.color = color
    self.edges = []
    self.traced = False

  def trace(self, counts, excludes):
    self.traced = True
    num = 1

    for edge in self.edges:
      if edge.traced:
        continue

      excludes[self.color].append(0)
      n = edge.trace(counts, excludes)
      p = n - excludes[self.color].pop()
      counts[self.color] += p * (p - 1) // 2 + p
      num += n

    excludes[self.color][-1] += num

    return num


def main():
  N = int(input())
  nodes = [Node(i, v - 1) for i, v in enumerate(map(int, input().split()))]
  counts = [0] * N
  excludes = [[0] for _ in range(N)]

  for _ in range(N - 1):
    a, b = map(int, input().split())
    nodes[a - 1].edges.append(nodes[b - 1])
    nodes[b - 1].edges.append(nodes[a - 1])

  num = nodes[0].trace(counts, excludes)
  pair = num * (num - 1) // 2 + num

  for i in range(len(counts)):
    p = num - excludes[i][0]
    counts[i] += p * (p - 1) // 2 + p

  for c in counts:
    print(pair - c)


if __name__ == '__main__':
  main()
