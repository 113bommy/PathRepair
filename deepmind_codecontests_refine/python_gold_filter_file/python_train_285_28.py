# Fast IO (only use in integer input)

# import os,io
# input=io.BytesIO(os.read(0,os.fstat(0).st_size)).readline

import heapq

T = int(input())
for _ in range(T):
    N = int(input())
    frontCamel = []
    backCamel = []
    indifferentCamel = []
    Happiness = 0
    for _ in range(N):
        k,l,r = map(int,input().split())
        if l > r:
            frontCamel.append((k,l-r))
            Happiness += r
        elif r > l:
            backCamel.append((N-k,r-l))
            Happiness += l
        else:
            indifferentCamel.append((k,0))
            Happiness += l
    frontQ = []
    backQ = []
    frontCamel.sort(key = lambda x:x[0])
    backCamel.sort(key = lambda x:x[0])
    for Camel in frontCamel:
        if Camel[0] == 0:
            continue
        if Camel[0] > len(frontQ):
            heapq.heappush(frontQ,Camel[1])
        else:
            if frontQ[0] < Camel[1]:
                heapq.heapreplace(frontQ,Camel[1])
    for Camel in backCamel:
        if Camel[0] == 0:
            continue
        if Camel[0] > len(backQ):
            heapq.heappush(backQ,Camel[1])
        else:
            if backQ[0] < Camel[1]:
                heapq.heapreplace(backQ,Camel[1])
    Happiness += sum(frontQ)
    Happiness += sum(backQ)
    print(Happiness)
