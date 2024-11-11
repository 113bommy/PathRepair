"""
Created on Sat 11st feb 2021
 @author: Rohit
"""

import math
arr= []
cap= []
w = int(input())
for _ in range(w):
    o,p = map(int, input().split())
    arr += [[p, o, _ + 1]]
h = int(input())
cap = list(map(int, input().split()))
capArr=[]
for _ in range(h):
    capArr += [[cap[_], _ +1, -1]]

arr.sort(reverse = True)
capArr. sort()
ans=[]
#print(arr)
sum= 0
for itr in arr:
    tar = itr[1]
    for qr in capArr:
        if qr[2] == -1 and qr[0] - tar >= 0:
            qr[2] = itr[2]
            sum += itr[0]
            ans += [qr]
            break


print(len(ans), sum)
for itr in ans:
    print(itr[2], itr[1])
        



    
    
    
            
