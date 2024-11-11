import heapq
t = int(input())
for _ in range(t):
    n = int(input())
    klr = [tuple(map(int, input().split())) for _ in range(n)]
    klr.sort()
    
    left = [[]for _ in range(n)]
    right = [[]for _ in range(n)]
    score = 0
    for K,L,R in klr:
        if K!=n:
            if L<R:
                score+=L
                right[n-K-1].append(R-L)
            elif R<L:
                score+=R
                left[K-1].append(L-R)
            else:
                score+=L
        else:
            score+=L
    
    def calc(ls):
        n = len(ls)
        use = []
        retval = 0
        for i in reversed(range(n)):
            for x in ls[i]:
                heapq.heappush(use, -x)
            if use:
                retval-=heapq.heappop(use)
        return retval
    score+=calc(left)
    score+=calc(right)
    print(score)
