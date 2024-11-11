import math
import queue

from itertools import permutations

n=int(input())
s=input()

def determine(t):
    for i in range(0,n-1):
        if t[i]==t[i+1] and t[i]!='?':
            return False
    
    for i in range(0,n-1):
        if t[i]=='?' and t[i+1]=='?':
            return True
    
    num=0
    
    if t[0]=='?' or t[n-1]=='?':
        return True
    
    for i in range(1,n-1):
        if t[i]=='?' and t[i-1]==t[i+1]:
            return True
    return False
        
    
if determine(s):
    print("YES")
else:
    print("No")
    