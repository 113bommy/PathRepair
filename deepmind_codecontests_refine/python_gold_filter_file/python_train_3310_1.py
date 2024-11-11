from heapq import heapify, heapreplace
n,m = map(int,input().split())
L = [  -i for i in map(int, input().split())]
heapify(L)
for _ in range(m):
    heapreplace(L,L[0]//2 + L[0]%2)
print(-sum(L))