# -*- coding: utf-8 -*-
"""
Created on Sat Mar  7 20:32:48 2020

@author: hp
"""

n = int(input())
s = input()
c1 =0
c2=0
ans=0
for i in range(len(s)):
    if(s[i]==")"):
        c1=c1+1
    else:
        c2 = c2 +1
        if(c1>=c2):
            ans = ans + 2
if(c1==c2):
    print(ans)
else:
    print(-1)