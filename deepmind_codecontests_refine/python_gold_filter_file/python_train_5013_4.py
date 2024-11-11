from itertools import permutations
import sys

n = int(input())

for _ in range(n):
    s = list(input())
    x = list(set(s))
    x.sort()
    if len(x) < 6:
        for p in permutations(x):
            for i,j in zip(p,p[1:]):
                if abs(ord(j)-ord(i)) == 1:
                    break
            else:
                break
        else:
            print("No answer")
            continue
    else:
        p = x[1::2] + x[::2]
    for c in p:
        print(c*s.count(c), end='')
    print()