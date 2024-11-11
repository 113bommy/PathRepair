import sys
input = sys.stdin.readline
from collections import Counter
import math
 
t = int(input())
 
 
for _ in range(t):
    n,m = list(map(int,input().split()))
    k = min(32,m)
    
    s = input().rstrip()
    
    D = set()
    v = 2**k - 1
    
    for i in range(m-k, len(s)-k+1):
        temp = s[i:i+k]
        #print(temp)
        D.add(v - int(temp,2))
    
    ok = 0
    
    cc = s[:m].count('0')
    if cc>0:
        on = 1
    else:
        on = 0
    for i in range(len(s)-m):
        if cc==0:
            on = 0
        if s[i]=='0':
            cc -= 1
        if s[i+m]=='0':
            cc += 1
        if cc==0:
            on = 0
    if on==1:
        print('YES')
        print(m*'0')
        ok = 1
    
    else:
        for i in range(v+1):
            if i not in D:
                ans = (bin(i))[2:]
                ans = (m - len(ans)) * '0' + ans
                print('YES')
                print(ans)
                ok = 1
                break
    
    if ok==0:
        print('NO')