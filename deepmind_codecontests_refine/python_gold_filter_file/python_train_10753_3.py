
import math
import sys
input=sys.stdin.readline
from collections import Counter, defaultdict, deque

def f(n,m, mp):
    #mp = collections.OrderedDict(sorted(mp.items()))
    #print(mp)
    cap = 2*n - m
    if cap%2 == 1:
        return "NO"
    blocked = 0
    for i in sorted(mp.keys()):
        if blocked:
            if len(mp[i]) == 2:
                return "NO"
            currow = mp[i][0]
            if(last_blocked[0] == currow):
                if(last_blocked[1]%2 == i%2):
                    return "NO"
                else:
                    blocked = 0
            else:
                if(last_blocked[1]%2 != i%2):
                    return "NO"
                else:
                    blocked = 0
        else:
            if len(mp[i]) == 1: 
                blocked = 1
                last_blocked = (mp[i][0], i)



    return "YES"
    


t = int(input())
result = []
for i in range(t):
    input()
    #n = int(input())
    mp = defaultdict(list)
    n, m = list(map(int, input().split()))
    for i in range(m):
        r, c = list(map(int, input().split()))
        mp[c].append(r)

    result.append(f(n, m, mp))
for i in range(t):
    print(result[i])

