#!/usr/bin/env python3
def func(a, i):
    return {a[0]:i, a[1]:i+1, a[2]:i+2}
A = {}
for i in range(3):
    A.update(func(input().split(), 3*i))
N = int(input())
b = [A.get(input(), -1) for _ in range(N)]
bingo = [[0, 1, 2], [3, 4, 5], [6, 7, 8],
         [0, 3, 6], [1, 4, 7], [2, 5, 8],
         [0, 4, 8], [2, 4, 6]]
for i in bingo:
    if set(i) <= set(b):
        print("Yes")
        break
else:
    print("No")