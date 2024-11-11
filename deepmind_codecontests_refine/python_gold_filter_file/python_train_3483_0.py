#: Author - Soumya Saurav
import sys,io,os,time
from collections import defaultdict
from collections import Counter
from collections import deque
from itertools import combinations
from itertools import permutations
import bisect,math,heapq
alphabet = "abcdefghijklmnopqrstuvwxyz"

input = sys.stdin.readline

########################################
import collections,sys,threading
sys.setrecursionlimit(10**9)
threading.stack_size(10**8)

def solve():
    t , k = map(int , input().split())
    nax = 10**5 + 5
    dp = [-1]*nax
    mod = 10**9 + 7
    dp[0] = 0
    def f(currflow):

        if currflow == 0:
            return 1

        if currflow < 0:
            return 1

        if dp[currflow] != -1: return dp[currflow]
        ans = 0
        ans += f(currflow - 1) # take red
        ans %= mod

        if currflow - k >= 0:
            ans += f(currflow - k) # take white
            ans %= mod

        dp[currflow] = ans

        return dp[currflow]

    pref_sum = [0]

    for i in range(nax):
        if dp[i] == -1: f(i)
        pref_sum.append(pref_sum[-1] + dp[i])

    for ii in range(t):
        a , b = map(int , input().split())
        print((pref_sum[b+1] - pref_sum[a])%mod)




threading.Thread(target=solve).start()
'''
# Wrap solution for more recursion depth
for dx,dy in [[1,0],[0,1],[-1,0],[0,-1]]:
#submit as python3



'''
