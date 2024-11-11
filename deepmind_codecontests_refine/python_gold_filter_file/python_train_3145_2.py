from heapq import *

n = int(input())

a = list(map(int, input().split()))
done = a.index(-1)

heap = []

cost = 0
x = n//2
position = n-1
while position > done:
    highest = a[position]
    he = min(heap) if heap else 10**10
    
    if highest < he:
        cost += highest
        for val in a[position-1:position-x:-1]:
            heappush(heap, val)
        position -= x
    else:
        cost += he
        heappop(heap)
        for val in a[position:position-x:-1]:
            heappush(heap, val)
        position -= x
    x //= 2
    
print(cost)
