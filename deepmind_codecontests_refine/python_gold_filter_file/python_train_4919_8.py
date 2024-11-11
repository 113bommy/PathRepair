# -*- coding: utf-8 -*-
"""
Created on Mon Aug 24 07:01:34 2020

@author: Dark Soul
"""

[n,s]=list(map(int, input().split()))
if 2*n>s:
    print('NO')
else:
    print('YES')
    sol=[1]*(n-1)
    sol.append(s-n+1)
    print(*sol)
    print(n)