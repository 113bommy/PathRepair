import heapq


def solve(a):
    pq = list()
    heapq.heapify(pq)
    delta = 0
    k = 0
    for i in range(len(a)):
        for x in a[i]:
            if k <= i:
                delta += x
                heapq.heappush(pq, x)
                k += 1
            elif pq:
                delta += x
                heapq.heappush(pq, x)
                delta -= heapq.heappop(pq)
    return delta


t = int(input())
while t > 0:
    t -= 1
    n = int(input())
    left = [list() for i in range(n)]
    right = [list() for i in range(n)]
    ans = 0
    for i in range(n):
        k, l, r = map(int, input().split())
        if l > r:
            left[k - 1].append(l - r)
        elif l < r:
            if k < n:
                right[n - 1 - k].append(r - l)
        ans += min(l, r)
    print(ans + solve(left) + solve(right))