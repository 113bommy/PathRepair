import sys
sys.setrecursionlimit(10**7)

readline = sys.stdin.buffer.readline
def readstr():return readline().rstrip().decode()
def readstrs():return list(readline().decode().split())
def readint():return int(readline())
def readints():return list(map(int,readline().split()))
def printrows(x):print('\n'.join(map(str,x)))
def printline(x):print(' '.join(map(str,x)))
import heapq


t = readint()
ans = []

for _ in range(t):
    n = readint()
    a = []
    b = []
    score = 0
    for i in range(n):
        k,l,r = readints()
        if k==n:
            score += l
        elif l>r:
            a.append([k,l,r])
            score += l
        elif l<r:
            b.append([n-k,l,r])
            score += r
        else:
            score += r
    a.sort()
    b.sort()
    left = []
    right = []
    heapq.heapify(left)
    heapq.heapify(right)
    lenl = 0
    lenr = 0
    for k,l,r in a:
        if k>lenl:
            heapq.heappush(left,[l-r,l,r])
            lenl += 1
        else:
            if l-r>left[0][0]:
                y = heapq.heappop(left)
                heapq.heappush(left,[l-r,l,r])
                score -= y[1]
                score += y[2]
            else:
                score -= l
                score += r
    for k,l,r in b:
        if k>lenr:
            heapq.heappush(right,[r-l,l,r])
            lenr += 1
        else:
            if r-l>right[0][0]:
                y = heapq.heappop(right)
                heapq.heappush(right,[r-l,l,r])
                score -= y[2]
                score += y[1]
            else:
                score -= r
                score += l
    ans.append(score)
printrows(ans)







