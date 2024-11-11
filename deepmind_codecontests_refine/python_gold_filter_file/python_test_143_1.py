import sys,os,io
from heapq import heapify, heappush, heappop
import math 
from collections import defaultdict
def ii():
    return int(input())
def li():
    return list(map(int,input().split()))
if(os.path.exists('input.txt')):
    sys.stdin = open("input.txt","r") ; sys.stdout = open("output.txt","w") 
else:
    input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

def solve():
    n = ii()
    a = li()
    a.sort()
    # if 0 not in a:
    #     print(*[-1 for i in range(n+1)])
    #     return 
    mex = n
    h = []
    kitna = [-1]*(n+1)
    ptr = 0
    for i in range(n):
        while ptr<n and a[ptr]<=i:
            heappush(h,-a[ptr])
            ptr+=1
        xy = 0
        if not h:
            # print("f",i,ptr)
            break
        x = -heappop(h)
        # if i==3:
        #     print("f",x,h)
        if x>i:
            break
        if i>0:
            xy = kitna[i-1]
        kitna[i] = xy
        kitna[i]+=i-x 
    d = defaultdict(lambda:0)
    for i in a:
        d[i]+=1 

    for i in range(n):
        if d[i]==0:
            mex = i 
            break 
    ans = []
    # prinT()
    # print(mex)
    f = 0
    for i in range(n+1):
        if f:
            ans.append(-1)
            continue
        if i==mex:
            ans.append(0)
            continue
        if i>0 and kitna[i-1]==-1:
            ans.append(-1)
            f = 1
            continue
            # break
        # if i!=n and a[i]>i:
        #     ans.append(-1)
        #     f = 1
        #     continue 
        # if i==2:
        #     print(x,d[i])
        # if i==0:
        #     print(d[i],kitna[i])
        xx = 0
        if i>0:
            xx = kitna[i-1]
        ans.append(d[i]+xx)

        # if i==a[i]:
        #     ans.append(d[i])
        # else:
        #     ans.append(d[i])
    print(*ans)


t = 1
t = ii()
for _ in range(t):
    solve()

# 0 0 1 1 2 3 
# 0 1 2 3 4 5

# 0 1 2 3 4 3 2
# 0 1 2 2 3 3 4
# 2 3
# 0 1 2 3 4

# 0 0 0 3


# 4 0 1 0 4
# 0 0 1 4 4
