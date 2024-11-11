from sys import stdin, stdout

__author__ = 'vks'

n = int(stdin.readline())
sticks = [int(i) for i in stdin.readline().split()]
sticks.sort()
square = 0
n -= 1
while n > 0:
    a = 0
    b = 0
    while n > 0 and abs(sticks[n] - sticks[n - 1]) > 1:
        n -= 1
    if n > 0:
        a = min(sticks[n], sticks[n - 1])
    n -= 2
    while n > 0 and abs(sticks[n] - sticks[n - 1]) > 1:
        n -= 1
    if n > 0:
        b = min(sticks[n], sticks[n - 1])
    n -= 2
    square += a * b
stdout.write(str(square) + "\n")
