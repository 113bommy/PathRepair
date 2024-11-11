import heapq
from sys import exit

import io
import os

input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

n = int(input())

heap = []

queries = []
for _ in range(2 * n):
    queries.append(input().split())

queries.reverse()

the_order_of_the_shuriken = []
for query in queries:
    if query[0].decode() == '-':
        if heap and heap[0] < int(query[1].decode()):
            exit(print('NO'))
        heapq.heappush(heap, int(query[1].decode()))
    else:
        if not heap:
            exit(print('NO'))
        the_order_of_the_shuriken.append(heapq.heappop(heap))

the_order_of_the_shuriken.reverse()
print('YES')
print(*the_order_of_the_shuriken)
