from sys import stdin, stdout
from collections import deque

n, m = map(int, stdin.readline().split())
ans = 0

for i in range(n):
    if i & 1:
        stdout.write('0')
    else:
        stdout.write('1')