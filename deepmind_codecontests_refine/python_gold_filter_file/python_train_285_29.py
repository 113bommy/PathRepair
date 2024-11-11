import sys 
from heapq import heapify,heappop,heappush,heappushpop
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

def main(N,K,L,R):
    left = [[] for _ in range(N)]
    right = [[] for _ in range(N)]
    score = 0
    for i in range(N):
        k = K[i]; l = L[i]; r = R[i]
        k -= 1
        if l >= r:
            left[k].append(l-r)
            score += r
        else:
            right[k].append(r-l)
            score += l
    q = []
    for n,xs in enumerate(left,1):
        for x in xs:
            if len(q) < n:
                heappush(q,x)
            else:
                heappushpop(q,x)
    score += sum(q)
    q = []
    for n,xs in enumerate(right[::-1][1:],1):
        for x in xs:
            if len(q) < n:
                heappush(q,x)
            else:
                heappushpop(q,x)
    score += sum(q)
    print(score)

T = int(readline())
for _ in range(T):
    N = int(readline())
    K, L ,R = [],[],[]
    for _ in range(N):
        k,l,r = map(int,readline().split())
        K.append(k)
        L.append(l)
        R.append(r)
    main(N,K,L,R)