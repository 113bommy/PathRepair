import bisect
N = int(input())
L = [int(i) for i in input().split(' ')]
L.sort()

sum = 0
for i,k in enumerate(L):
  for j in range(i+1, N):
    sum += bisect.bisect_left(L,L[j] + k) - j - 1


print(sum)