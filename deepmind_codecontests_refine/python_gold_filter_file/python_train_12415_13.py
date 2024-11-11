# -*- coding: utf-8 -*-
"""
Created on Wed Jun 17 13:21:48 2020

@author: Mridul Garg
"""
o = int(input())
for _ in range(o):
    n = int(input())
    A = list(map(int, input().split(' ')))
    dic = {}
    for i in range(n+2):
        dic[i] = 0
    for i in A:
        if i in dic:
            dic[i] += 1
    
    def Find(x):
        for i in range(x+1, n+2):
            if dic[i] == 0:
                return i
    def CHECK():
        done = False
        for i in range(1, n):
            if A[i] < A[i-1]:
                return done
        return True
    
    ans = []
    i = 0
    result = False
    while i < n:
#        print(A)
        if result:
            break
        
        if A[i] == i:
            i+=1
            continue
        
        mex = Find(i-1)
#        print(mex)
        if mex < n and A[mex] != mex:
            dic[mex] += 1
            dic[A[mex]] -= 1
            A[mex] = mex
            ans.append(mex)
            result = CHECK()
#            i += 1
        else:
            for j in range(i+1, n):
                
                if A[j] == i:
                    temp = mex
                    dic[A[j]] -= 1
                    A[j] = temp
                    dic[temp] += 1
                    
                    ans.append(j)
#                    print(A)
                    result = CHECK()
#                    i += 1
                    break
                
#        
#        mex = Find()
#        if A[i] != i:
#            temp = Find(i-1)
#            dic[temp] += 1
#            dic[A[i]] -= 1
#            A[i] = temp
#            ans.append(i)
#            print(A)
#            result = CHECK()
        
        
#    print(A)
        
#    print(result)   
#    print(A)
    print(len(ans))
    for i in ans:
        print(i+1, end = " ")