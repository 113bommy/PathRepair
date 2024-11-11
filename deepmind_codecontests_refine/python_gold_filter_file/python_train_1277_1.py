import sys
import math
import bisect
from sys import stdin, stdout
from math import gcd, floor, sqrt, log2, ceil,pi,sin,cos,acos,atan
from collections import defaultdict as dd
from bisect import bisect_left as bl, bisect_right as br
from bisect import insort
from collections import Counter
from collections import deque
from heapq import heappush,heappop,heapify
from itertools import permutations,combinations
mod = int(1e9)+7

 
ip = lambda : int(stdin.readline())
inp = lambda: map(int,stdin.readline().split())
ips = lambda: stdin.readline().rstrip()
out = lambda x : stdout.write(str(x)+"\n")

t = ip()
for _ in range(t):
    n = ip()
    arr = list(inp())
    ans = [max(arr)]
    sam = ans[0]
    arr.remove(max(arr))
    while arr:
        dic = {}
        n = len(arr)
        for i in range(n):
            test = gcd(sam,arr[i])
            dic[test] = i
        ch = max(list(dic.keys()))
        pos = dic[ch]
        sam = gcd(ch,sam)
        ans.append(arr[pos])
        del arr[pos]
    print(*ans)
            
            
        
        
            
        
                
            
        
                        
                        
                        
                    
        
        
        
        
            
            
    
