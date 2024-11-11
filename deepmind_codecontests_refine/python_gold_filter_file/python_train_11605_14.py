# 485A

from sys import stdin

__author__ = 'artyom'

a, m = map(int, stdin.readline().strip().split())
rem = a % m
z = set()
z.add(rem)
while rem > 0:
  a += rem
  rem = a % m
  if rem in z:
    print('No')
    exit()
  z.add(rem)
print('Yes')