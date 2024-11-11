N, K = map(int,input().split())
A = list(map(int,input().split()))

import math
K = min(K, 43)
for k in range(K):
  light = [0] * (N+1)
  for i in range(N):
    start = max(0,i-A[i])
    end = min(N-1, i+A[i])
    light[start] += 1
    light[end+1] -= 1
  for i in range(1,N):
    light[i] += light[i-1]
    
  A = light

light.pop()
print(" ".join(map(str,light)))
