import math

elem = int(input())
ar = []
stolen = []
for t in input().split(" "):
    ar.append(int(t))
tempMax = max(ar)
for i in ar:
    stolen.append(tempMax-i)
curr = math.gcd(stolen[0], stolen[1])
for x in range(len(stolen)):
    if x ==0 or x==1:
        continue
    else:
        curr = math.gcd(curr, stolen[x])
print(int(sum(stolen)/curr), curr)
