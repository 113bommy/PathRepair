#     Codeforces Round #488 by NEAR (Div. 2)
import collections
from functools import cmp_to_key
#key=cmp_to_key(lambda x,y: 1 if x not in y else -1 )

import sys
def getIntList():
    return list(map(int, input().split()))    

import bisect 

def makePair(z):
    return  [(z[i], z[i+1]) for i in range(0,len(z),2) ]
            
N,M =  getIntList()
p1 = getIntList()
p1 = makePair(p1)
p1 = list(map( set, p1))
p2 = getIntList()
p2 = makePair(p2)
p2 = list(map( set, p2))
#print(p1)

res = set()
for x in p1:
    for y in p2:
        z = x&y
        if len(z) ==2 or len(z) ==0:continue
        res = res | z
if len(res) == 1:
    print(res.pop())
    sys.exit()

for x in p1:
    nz = set()
    for y in p2:
        z = x&y
        if len(z) ==2 or len(z) ==0:continue        
        nz = nz | z
    if len(nz) == 2:
        print(-1)
        sys.exit()

for x in p2:
    nz = set()
    for y in p1:
        z = x&y
        if len(z) ==2 or len(z) ==0:continue        
        nz = nz | z
    if len(nz) == 2:
        print(-1)
        sys.exit()

print(0)
