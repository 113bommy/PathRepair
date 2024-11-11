from heapq import heappush, heappop
T = int(input())

def process(arr):
    arr.sort()
    baseS = 0
    diffS = 0
    q = []
    length = 0
    for K, L, R in arr:
        baseS += R
        diff = L - R
        heappush(q, diff)
        diffS += diff
        length += 1
        while length > K:
            d = heappop(q)
            diffS -= d
            length -= 1
    return baseS + diffS

for _ in range(T):
    N = int(input())
    arr1 = []
    arr2 = []
    for _ in range(N):
        K, L, R = list(map(int, input().split()))
        if L > R:
            arr1.append((K, L, R))
        else:
            arr2.append((N-K, R, L))
    print(process(arr1) + process(arr2))
