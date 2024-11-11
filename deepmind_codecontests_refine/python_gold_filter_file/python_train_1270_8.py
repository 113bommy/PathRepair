q=int(input())
for qq in range(q):
    n = int(input())
    a = list(map(int, input().split()))
    if n==1:
        print("-1")
        continue
    first = {}
    last = {}

    for i in range(n):
        elem = a[i]
        if elem not in first:
            first[elem] = i
        elif elem not in last:
            last[elem] = i
        else:
            if last[elem] - first[elem] >= i - last[elem]:
                first[elem] = last[elem]
                last[elem] = i

    dist = n+1
    for x in first:
        if x not in last: continue
        if last[x] - first[x] + 1 < dist:
            dist = last[x] - first[x] + 1
    if dist <= 1 or dist > n:
        print(-1)
    else:
        print(dist)
