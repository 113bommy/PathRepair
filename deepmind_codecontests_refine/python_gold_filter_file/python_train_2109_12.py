import sys
from bisect import bisect_left
from collections import defaultdict

input = lambda: sys.stdin.readline().rstrip()
R = lambda : map(int,input().split())

#print("executing")
T, = R()
for _ in range(T):
    n, = R()
    s = input()
    ans = ''
    idx = n
    for i in range(n):
        if(s[i] == '0'):
            ans += '0'
        else:
            idx = i
            break
    allone = True
    for i in range(idx, n, 1):
        if(s[i] == '0'):
            allone = False
            break
    if(allone):
        ans += '1'*(n-idx)
    else:
        ans += '0'
        for i in range(n-1, idx-1, -1):
            if(s[i] == '1'):
                ans += '1'
            else:
                break
    print(ans)
    
