import sys
input = sys.stdin.readline

def getInts():
    return [int(s) for s in input().split()]

def getInt():
    return int(input())

def getStrs():
    return [s for s in input().split()]

def getStr():
    return input().strip()

def listStr():
    return list(input().strip())

import collections as col

"""

"""

M = 10**9+7

def solve():
    N = getInt()
    S = listStr()
    # this is the base case. With no characters, 
    dp = [1,0,0,0]
    #0th element initialises, 1st is instances of a, 2nd is instances of ab, 3rd is instances of abc
    #string is abc
    #a: dp is [1,1,0,0]
    #b: dp is [1,1,1,0]
    #c: dp is [1,1,1,1]
    
    #string is abbcbc
    #[1,1,0,0], [1,1,1,0], [1,1,2,0], [1,1,2,2], [1,1,3,2], [1,1,3,5]
    ref = {'a': 1, 'b': 2, 'c': 3}
    
    #string is ac?b?c
    #[1,1,0,0], [1,1,0,0], [3,4,1,0], [3,4,5,0], [9,15,19,5], [9,15,19,24]
    for s in S:
        tmp = list(dp)
        if s == '?':
            for i in range(4):
                #we have all the existing possibilities multiplied by 3
                tmp[i] *= 3
                tmp[i] %= M
            for i in range(1,4):
                #each possible value a,b,c, we also add the previous number ending with letter prior to that
                tmp[i] += dp[i-1]
                tmp[i] %= M
        else:
            x = ref[s]
            #same logic as above but for only one value
            tmp[x] += dp[x-1]
            tmp[x] %= M
        dp = list(tmp)
        
        #print(dp)
    return dp[3]
    
    
    
print(solve())   
    