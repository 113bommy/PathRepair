n, k = [int(s) for s in input().split(' ')]
houses = [int(s) for s in input().split(' ')]
maxN = 1
tmpN = 1
for i in range(n-1):
    tmpN += int(houses[i] != houses[i+1])
    maxN = max(maxN, tmpN)
    tmpN = int(houses[i] != houses[i+1]) * tmpN + int(houses[i] == houses[i+1])
print(maxN)