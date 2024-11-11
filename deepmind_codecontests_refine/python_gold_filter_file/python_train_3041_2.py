###############################
# https://codeforces.com/contest/1269/problem/D
# 2021/01/13
# WenhuZhang
################################
from sys import stdin
import collections
import copy

n= int(stdin.readline())
a = list(map(int, stdin.readline().split()))
ans =0
left=[]
for i in range(len(a)):
    # print(ans, left)
    ans += a[i]//2
    if a[i]%2 :
        if not len(left):
            left.append(i)
        elif (i-left[-1])%2:
            # print(i,a)
            left.pop()
            ans+=1
        else:
            left.append(i)
    
print(ans)
        
    
