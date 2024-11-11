import heapq
n,m = [int(i) for i in input().split()]
a = [int(i) for i in input().split()]
b = a[:]

# find min
heapq.heapify(b)
c = 0
p_min = 0
while b and c<n:
    v = heapq.heappop(b)
    p_min+=v
    if v>1:
        heapq.heappush(b,v-1)
    c+=1

# find max
heapq._heapify_max(a)
c = 0
p_max = 0
while a and c<n:
    v = heapq.heappop(a)
    p_max+=v
    if v>1:
        heapq.heappush(a,v-1)
        heapq._heapify_max(a)
    c+=1


print(p_max,p_min)