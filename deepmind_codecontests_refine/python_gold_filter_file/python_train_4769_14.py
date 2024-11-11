import heapq

q = int(input())
inf = 10000000000
left = [inf]
right = [inf]
minval = 0
for _ in range(q):
    query = list(map(int, input().split()))
    if query[0] == 1:
        _, a, b = query
        if a < -left[0]:
            v = -heapq.heappop(left)
            heapq.heappush(right, v)
            heapq.heappush(left, -a)
            heapq.heappush(left, -a)
            minval += abs(v - a) + b
        elif a > right[0]:
            v = heapq.heappop(right)
            heapq.heappush(left, -v)
            heapq.heappush(right, a)
            heapq.heappush(right, a)
            minval += abs(v - a) + b
        else:
            heapq.heappush(left, -a)
            heapq.heappush(right, a)
            minval += b
    else:
        print(-left[0], minval)