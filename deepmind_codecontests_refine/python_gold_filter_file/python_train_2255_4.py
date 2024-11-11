import bisect

n, q = map(int, input().split())
a, k, curA, curK = [], [], 0, 0

for s in input().split():
    curA += int(s)
    a.append(curA)

for s in input().split():
    curK += int(s)
    index = bisect.bisect(a, curK)

    if index == n:
        print(n)
        curK = 0
    else:
        print(n - index)
    
