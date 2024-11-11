import sys
from itertools import combinations as c
for line in sys.stdin:
    count = 0
    k, v = map(int, line.split())
    if k or v:
        for i in c(range(10), k):
            if sum(i) == v:
                count += 1
    else:
        break
    print(count)