import itertools
import math
n=input()
n=int(n)
zoma=int(n/2)
posArray = [int(x) for x in input().split()]
posArray.sort()
evenCount=0
oddCount=0
for i, j in zip(range(n,0,-2), range(zoma-1,-1,-1)):
    if posArray[j]!=i:
        evenCount += abs(i-posArray[j])

for i, j in zip(range(n-1,0,-2), range(zoma-1,-1,-1)):
    if posArray[j] != i:
        oddCount += abs(i-posArray[j])

print(min(evenCount,oddCount))