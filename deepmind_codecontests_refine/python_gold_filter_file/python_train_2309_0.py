import math
from collections import Counter
t = 1
for _ in range(t):
    n = int(input())
    # s = input()
    # n,m = map(int, input().split())
    ali = list(map(int, input().split()))
    ali.sort()
    c = Counter()
    s = set()
    for i in range(n):
        if( ali[i]-1 not in s and ali[i]-1 != 0):
            s.add(ali[i]-1)
        elif(ali[i] not in s):
            s.add(ali[i])
        else:
            s.add(ali[i]+1)
    print(len(s))
                




