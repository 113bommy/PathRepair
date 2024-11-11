import bisect
from collections import *
n = int(input())
while n!=0:
    s = input()
    t = input()
    dc = defaultdict(list)
    for i in range(len(s)):
        dc[s[i]].append(i)    
    i = 0
    pos = -1
    ans = 1
    while i < len(t):
        if len(dc[t[i]]) == 0:
            ans = -1
            break
        x = bisect.bisect_right(dc[t[i]],pos)
        if x>=len(dc[t[i]]):
            ans+=1
            pos=-1
        else:
            pos = dc[t[i]][x]
            i+=1
    print(ans)
    n-=1




