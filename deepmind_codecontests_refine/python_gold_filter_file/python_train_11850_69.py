import math

N,M = map(int,input().split())
A = M//N
L = []
for i in range(1,int(math.sqrt(M))+1):
  if (M%i == 0 and i <= A):
    L.append(i)
    if (M//i <= A):
      L.append(M//i)
print(max(L))