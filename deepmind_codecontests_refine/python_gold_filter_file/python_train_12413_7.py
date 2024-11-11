# -*- coding: utf-8 -*-
"""
Created on Tue Jun 16 18:48:55 2020

@author: user
"""
def solve(n,l):
    temp=set(l)
    d=len(temp)
    dic={}
    for i in range(n):
        if(l[i] not in dic):
            dic[l[i]]=1
        else:
            dic[l[i]]+=1
    #print(dic)
    s=(max(dic.values()))
    if(s==d):
        print(d-1)
    else:
        print(min(d,s))
    
t=int(input())
for i in range(t):
    n=int(input())
    l=list(map(int,input().split()))
    solve(n,l)