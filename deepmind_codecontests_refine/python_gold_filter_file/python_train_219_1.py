from sys import stdin
from collections import deque
import heapq

def realDist(n,long):
    out = []

    dists = [x[0] + x[1] for x in long]
    #print(dists)

    d2 = [(-1, -1)] + sorted([(dists[x], long[x][0]) for x in range(len(long))])
    
    before = 0
    after = d2[-1][0]

    ind = 0
    
    for x in range(n):
        if ind < len(long):
            if long[ind][0] < x:
                before = max(before, n-1+long[ind][1])
                ind += 1
        out.append(max(before,after))
        before -= 1
        after -= 1
    return out

n,m = [int(x) for x in stdin.readline().split()]

candy = {}

long = []
maxLen = 0

for c in range(m):
    a,b = [int(x) for x in stdin.readline().split()]

    a -= 1
    b -= 1

    b = (b-a)%n

    if a in candy:
        heapq.heappush(candy[a],b)
        if len(candy[a]) == maxLen:
            long.append(a)
        elif len(candy[a]) > maxLen:
            long = [a]
            maxLen = len(candy[a])
    else:
        candy[a] = [b]
        if maxLen == 0:
            maxLen = 1
            long = [a]
        elif maxLen == 1:
            long.append(a)

long2 = long[:]
long = [(x+candy[x][0])%n for x in long]
long3 = [(x,candy[x][0]) for x in long2]

long4 = []

for c in candy:
    if len(candy[c]) == maxLen-1:
        long4.append((c, candy[c][0]))

long.sort()
long2.sort()
long3.sort()
long4.sort()

longSet = set(long)

base = n*maxLen-n
ind = 0

out = [x+base for x in realDist(n,long3)]

out2 = [x+base-n for x in realDist(n,long4)]

out3 = [max(out[x], out2[x]) for x in range(n)]

print(' '.join([str(x) for x in out3]))
        
