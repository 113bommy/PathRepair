from math import *
from operator import *
 
t = int(input())
 
for _ in range(t):
    a, b = map(int, input().split())
    s = input()
    l = list()
    p, q = 0, 0
    s = '0' + s + '0'
    for i in range(len(s)):
        if s[i] == '1' and s[i-1] == '0':
            p = i
        elif s[i] == '0' and s[i-1] == '1':
            q = i - 1
            l.append([p, q])
    answer = 0
    f = False
    if len(l) == 0:
        print(0)
    else:
        for i in range(0, len(l)-1):
            if (l[i+1][0] - l[i][1] - 1) * b <= a:
                answer += (l[i+1][0] - l[i][1] - 1) * b
                f = True
            elif f:
                f = False
                answer += a
            else:
                answer += a
        print(answer + a)

        