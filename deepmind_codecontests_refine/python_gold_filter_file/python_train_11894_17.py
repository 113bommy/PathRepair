# -*- coding: utf-8 -*-
"""
Created on Sat May  9 10:00:54 2020

@author: xdcao@zju.edu.cn
"""
def solve(n):
    if n == 2 or n == 3:
        print(-1)
        return
    if n == 4:
        print(' '.join(list(map(str, [2, 4, 1, 3]))))
        return
    if n == 5:
        print(' '.join(list(map(str, [1,3,5,2,4]))))
        return
    if n == 6:
        print(' '.join(list(map(str, [1,4,6,3,5,2]))))
        print()
    else:
        arr1 = []
        arr2 = []
        for i in range(1, n+1):
            if i % 2 == 1:
                arr1.append(i)
            else:
                arr2.append(i)        
        if n % 2 == 1:
            t1 = arr2.pop()
            t2 = arr2.pop()
            arr2.append(t1)
            arr2.append(t2)
            arr2 = arr2[::-1]
            print(' '.join(list(map(str, arr1+arr2))))
        else:
            t1 = arr1.pop()
            t2 = arr1.pop()
            t3 = arr2.pop()
            t4 = arr2.pop()
            arr1.append(t4)
            arr1.append(t3)
            arr2.append(t1)
            arr2.append(t2)
            arr2 = arr2[::-1]
            print(' '.join(list(map(str, arr1+arr2))))
        
T = int(input())

for ti in range(1, T+1):
    n = int(input())
    solve(n)