# -*- coding: utf-8 -*-
"""
Created on Mon Oct 12 01:15:21 2020

@author: Dark Soul
"""

[n,k]=list(map(int,input().split()))
arr=list(map(int,input().split()))
a=[]
for i in range(n):
    a.append([arr[i],i+1])
a.sort(reverse=True)
b=[]
ans=0
for i in range(k):
    ans+=a[i][0]
    b.append(a[i][1])
b.sort()
print(ans)
shuru=0
sol=[]
for i in range(len(b)):
    if i!=len(b)-1:
        sol.append(b[i]-shuru)
        shuru=b[i]
    else:
        sol.append(n-shuru)
print(*sol)