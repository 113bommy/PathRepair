from heapq import *

def find_add(a, k):
    extra = a%k
    return (k-extra)*((a//k)**2) + extra*((1+(a//k))**2)

n, mx = map(int, input().split())
lst = list(map(int, input().split()))
a = []
heapify(a)
    
for i in lst:
    heappush(a, (find_add(i, 2)-find_add(i, 1), i, 1))
    
total = n

while total != mx:
    curr_cont, el, k = heappop(a)
    new = (find_add(el, k+2)-find_add(el, k+1), el, k+1)
    heappush(a, new)
    total += 1

sc = 0 
while a:
    curr_cont, el, k = heappop(a)
    sc += find_add(el, k)
    
print(sc)