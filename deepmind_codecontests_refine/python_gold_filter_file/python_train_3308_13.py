import sys
input = sys.stdin.readline

N = int(input())
LIMIT = min(N,4195)

V = [0] * N
W = [0] * N
for i in range(N):
    nV, nW = map(int, input().split())
    V[i] = nV
    W[i] = nW

pre = [[] for i in range(LIMIT)]

for i in range(LIMIT):
    if i == 0:
        pre[i] = [(0,0), (W[i], V[i])]
        continue

    curr = pre[i]
    prev = pre[(i - 1)//2]
    nV, nW = V[i], W[i]
    
    size = len(prev)

    left = 0
    right = 0
    while left < size or right < size:
        if left == size or prev[left][0] > prev[right][0] + nW or (prev[left][0] == prev[right][0] + nW and prev[left][1] < prev[right][1] + nV):
            if len(curr) == 0 or prev[right][1] + nV > curr[-1][1]:
                curr.append((prev[right][0] + nW, prev[right][1] + nV))
            right += 1
        else:
            if len(curr) == 0 or prev[left][1] > curr[-1][1]:
                curr.append(prev[left])
            left += 1
            
Q = int(input())
out = [0] * Q
for t in range(Q):
    vert, L = map(int, input().split())
    vert -= 1

    stack = []
    while vert >= LIMIT:
        stack.append((V[vert], W[vert]))
        vert = (vert - 1) // 2
        
    prev = pre[vert]
    best = 0
    
    for i in range(1 << len(stack)):
        sV = 0
        sW = 0
        red = i
        for nV, nW in stack:
            if red & 1:
                sV += nV
                sW += nW
            red >>= 1

        limit = L - sW
        if limit < 0:
            continue
        
        lo = -1
        hi = len(prev)
        while hi - lo > 1:
            test = (hi + lo) // 2
            if prev[test][0] <= limit:
                lo = test
            else:
                hi = test
                
        if lo >= 0:
            new = prev[lo][1] + sV
            best = max(best, new)
        
    out[t] = best

print('\n'.join(map(str,out)))
