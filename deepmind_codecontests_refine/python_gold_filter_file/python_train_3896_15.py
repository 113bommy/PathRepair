#!/usr/bin/python3

def readln(): return tuple(map(int, input().split()))

r1, c1, r2, c2 = readln()
ans = [0, 0, 0]
if r1 == r2 or c1 == c2:
    ans[0] = 1
else:
    ans[0] = 2
if abs(r1 - r2) == abs(c1 - c2):
    ans[1] = 1
elif (abs(r1 - r2) % 2 == 0) == (abs(c1 - c2) % 2 == 0):
    ans[1] = 2
ans[2] = max(abs(r1 - r2), abs(c1 - c2))
print(*ans)
