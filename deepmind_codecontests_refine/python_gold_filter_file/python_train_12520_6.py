from __future__ import division, print_function
import sys
if sys.version_info[0] < 3:
    from __builtin__ import xrange as range
    from future_builtins import ascii, filter, hex, map, oct, zip

import os, sys, bisect, copy
from collections import defaultdict, Counter, deque
#from functools import lru_cache   #use @lru_cache(None)
if os.path.exists('in.txt'): sys.stdin=open('in.txt','r')
if os.path.exists('out.txt'): sys.stdout=open('out.txt', 'w')
#
def input(): return sys.stdin.readline()
def mapi(arg=0): return map(int if arg==0 else str,input().split())
#------------------------------------------------------------------

import sys
sys.setrecursionlimit(10**5+10)
from types import GeneratorType
#use:- put @bootstrap overrecursive function
def bootstrap(func, stack=[]):
    def wrapped_function(*args, **kwargs):
        if stack:
            return func(*args, **kwargs)
        else:
            call = func(*args, **kwargs)
            while True:
                if type(call) is GeneratorType:
                    stack.append(call)
                    call = next(call)
                else:
                    stack.pop()
                    if not stack:
                        break
                    call = stack[-1].send(call)
            return call
    return wrapped_function


mod = int(1e9+7)
for _ in range(int(input())):
    n = int(input())
    gr = defaultdict(list)
    for i in range(n-1):
        x,y = mapi()
        gr[x].append(y)
        gr[y].append(x)
    m = int(input())
    p = list(mapi())
    # p = p+[1]*(n-1-len(p))
    while len(p)<n-1:
        p.append(1)
    p.sort()
    for i in range(n-1,len(p),1):
        p[n-2] = p[n-2]*p[i]%mod
    p = p[:n-1]
    p = p[::-1]
    sz = [1]*(n+1)
    @bootstrap
    def dfs(s,par):
        for i in gr[s]:
            if i==par: continue
            yield dfs(i,s)
            sz[s] +=sz[i]
        yield 0
    dfs(1,-1)
    count = []
    for i in range(1,n+1):
        count.append(sz[i]*(n-sz[i]))
    count.sort(reverse=True)
    res = 0
    for i in range(n-1):
        res+=p[i]*count[i]%mod
        res%=mod
    print(res)
