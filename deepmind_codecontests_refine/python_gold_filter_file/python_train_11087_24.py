#~ import io
#~ import sys
#~ import time

#~ start = time.clock()
#~ test = '''5
#~ 1 2 3 1 2'''
#~ test = '''4
#~ 3 2 1 4'''
#~ sys.stdin = io.StringIO(test)

n = int(input())
floors = list(map(int, input().split()))
#~ print(floors)
ma = floors[:]
max_so_far = float("-inf")
for i in range(n-1,-1,-1):
   ma[i] = max(0,1+max_so_far-floors[i])
   max_so_far = max(max_so_far,floors[i])
   
print(" ".join(map(str,ma)))   
