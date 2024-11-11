import sys
import math


lines = sys.stdin.read().splitlines()
n = [int(x) for x in lines[0].split()][0]
kids = [int(x) for x in lines[1].split()]
kids = sorted(kids)
kidsArr = []
for i in reversed(range(n-1, -1, -2)):
    kidsArr.append(kids[i])
for i in range(n-2, -1, -2):
    kidsArr.append(kids[i])

for i in range(0, len(kids)):
    print(kidsArr[i], end=' ' if n != i else '\n')
# print([x for x in sorted(kids)])

# n = [int(x) for x in lines[0].split()][0]
# nextA, nextB = 0, 0
# totalCount = 1
# lastDraw = 0
# for i in range(0, n):
#     a, b = nextA, nextB
#     nextA, nextB = [int(x) for x in lines[i+1].split()]
#     diff = min(nextA, nextB)-max(a, b)
#     if diff >= 0:
#         if lastDraw != max(a, b):
#             diff += 1
#             lastDraw = min(nextA, nextB)
#     print(max(0, diff))
#     totalCount += max(0, diff)

# print(totalCount)
