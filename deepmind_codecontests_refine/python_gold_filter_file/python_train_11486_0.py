from collections import deque, defaultdict
from sys import stdout

def searchPath(n, k):
    def getNexts(curr):
        lb = max(k - curr, curr - k)
        ub = min(n - max(0, k + curr - n), curr + k)
        return range(lb, ub + 1, 2)
    processed = [False for _ in range(n + 1)]
    deq = deque()
    deq.append(0)
    prev = [None for _ in range(n + 1)]
    while len(deq) > 0 and not processed[n]:
        x = deq.popleft()
        processed[x] = True
        nexts = getNexts(x)
        for xNext in nexts:
            if not processed[xNext]:
                processed[xNext] = True
                prev[xNext] = x
                deq.append(xNext)
    if not processed[n]:
        return None
    result = []
    x = n
    while x > 0:
        result.append(x)
        x = prev[x]
    return result[::-1]

def solve(n, k):
    fullSet = set(range(1, n+1))
    path = searchPath(n, k)
    if path is None:
        return None
    currSet = set()
    result = 0
    for length in path:
        currLen  = len(currSet)
        inSet = int((currLen + k - length)/ 2)
        outSet = k - inSet
        a = []
        for i, x in enumerate(currSet):
            if i == inSet:
                break
            a.append(x)
        currAntiSet = fullSet - currSet
        for x in a:
            currSet.remove(x)
        for i, x in enumerate(currAntiSet):
            if i == outSet:
                break
            a.append(x)
            currSet.add(x)
        print('?', *a)
        result = result ^ int(input())
    return result
def printResult(result):
    if result is None:
        print(-1)
    else:
        print('!',result)
#t = int(input())
t = 1
results = deque()
for _ in range(t):
    n, k = list(map(int, input().split(' ')))
    result = solve(n, k)
    printResult(result)