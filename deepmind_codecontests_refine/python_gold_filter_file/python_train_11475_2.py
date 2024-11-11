from bisect import bisect_left as bl
from bisect import bisect_right as br
import heapq
import math
from collections import *
from functools import reduce,cmp_to_key
import sys
input = sys.stdin.readline
 
# M = mod = 998244353
def factors(n):return sorted(list(set(reduce(list.__add__,([i, n//i] for i in range(1, int(n**0.5) + 1) if n % i == 0)))))
# def inv_mod(n):return pow(n, mod - 2, mod)
 
def li():return [int(i) for i in input().rstrip('\n').split(' ')]
def st():return input().rstrip('\n')
def val():return int(input().rstrip('\n'))
def li2():return [i for i in input().rstrip('\n').split(' ')]
def li3():return [int(i) for i in input().rstrip('\n')]


va = 10**7
helpl = defaultdict(deque)
def dfs(i):
    global va
    curr = []
    # print('currnode : ',i)
    for j in d[i]:
        curr.extend(dfs(j))
    curr = sorted(list(curr))
    # print('currlen : ',curr,'c value : ',c[i-1])
    if len(curr) < c[i-1]:
        print('NO')
        exit()
    if not len(curr):
        curr.append(va)
        helpl[va].append(i-1)
        va -= 2000
    else:
        # if c[i-1] == 0:
        #     # curr.append(curr[0] - 1)
        #     helpl[curr[0]].append(i-1)
        
        # print(curr)
        for j in range(c[i-1]):
            helpl[curr[j] - 1].append(helpl[curr[j]].popleft())
            curr[j] -= 1
        for j in range(len(curr)-1,c[i-1]-1,-1):
            helpl[curr[j] + 1].append(helpl[curr[j]].popleft())
            helpl[curr[j]] = deque()
            curr[j] += 1
        # print(curr,c[i-1])
        
        
        if c[i-1] == len(curr):curr.append(curr[-1] + 1)
        else:curr = curr[:c[i-1]] + [curr[c[i-1]]-1] + curr[c[i-1]:]
        helpl[curr[c[i-1]]].append(i-1)
        # print(helpl)
        # for i in helpl:
            
        #     if len(helpl[i]):
        #         helpl[i] = deque(sorted(helpl[i]))
    return curr


n = val()
d = defaultdict(list)
c = []
a = [0 for i in range(n)]
for i in range(n):
    x,y = li()
    d[x].append(i + 1)
    c.append(y)
# print(d)
root = d[0][0]
d.pop(0)
for i in d:
    d[i] = sorted(d[i])
# print(d,c,root)
dfs(root)
curr = 1
# print(helpl)
for i in sorted(helpl):
    # print(i)
    for j in helpl[i]:
        a[j] = curr
    if len(helpl[i]):curr += 1
print('YES')
print(*a)



