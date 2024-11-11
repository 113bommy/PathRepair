from sys import stdin, stdout
#import math
from collections import deque

input = stdin.readline

n = int(input())
seqB = list(input())
seqW = seqB.copy()

for i in range(0, n):
    if seqB[i] == 'B':
        seqB[i] = True
        seqW[i] = False
    else:
        seqB[i] = False
        seqW[i] = True

opsB = deque()
opsW = deque()

for i in range(0, n - 1):
    if not seqB[i]:
        seqB[i] = not seqB[i]
        seqB[i+1] = not seqB[i+1]
        opsB.append(i + 1)
for i in range(0, n - 1):
    if not seqW[i]:
        seqW[i] = not seqW[i]
        seqW[i + 1] = not seqW[i + 1]
        opsW.append(i + 1)

if not seqB[n - 1]:
    if not seqW[n - 1]:
        print(-1)
    else:
        print(len(opsW))
        print(*opsW)
else:
    print(len(opsB))
    print(*opsB)