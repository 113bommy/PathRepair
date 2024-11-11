# import sys

# sys.stdin = open('input.txt', 'r')
# sys.stdout = open('output.txt', 'w')

s = input()
nb, ns, ne = map(int, input().split())
pb, ps, pe = map(int, input().split())
r = int(input())

bfor1 = s.count('B')
sfor1 = s.count('S')
cfor1 = s.count('C')

minBurg = 0; maxBurg = 10**13
while minBurg < maxBurg:
    burg = (minBurg + maxBurg)//2
    cost = max((burg*bfor1 - nb), 0)*pb + max((burg*sfor1-ns), 0)*ps + max(0, (burg*cfor1-ne))*pe
    if cost <= r:
        minBurg = burg + 1
    else:
        maxBurg = burg
    # print(minBurg, maxBurg)
print(maxBurg-1)
    