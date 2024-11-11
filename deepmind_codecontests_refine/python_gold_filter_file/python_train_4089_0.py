import collections
t = int(input())
for _ in range(t):
    # print('time', _)
    
    n, x, y = map(int, input().split())
    b = [int(i) for i in input().split()]

    if x == n:
        print("YES")
        for i in b:
            print(i, end = ' ')
        print()
        continue
    setB = set(b)
    noin = 1
    while noin in setB:
        noin += 1
    cnt = collections.deque([i, j] for i, j in collections.Counter(b).most_common())
    cnt2 = collections.deque()
    pos = [set() for _ in range(n + 2)]
    for i in range(len(b)):
        pos[b[i]].add(i)
    res=[-1] * n
    l = x
    
    while l > 0:
        i = cnt.popleft()  
        i[1] -= 1
        if i[1] != 0:
            cnt2.appendleft(i)
        while not cnt or cnt2 and cnt2[0][1] >= cnt[0][1]:
            cnt.appendleft(cnt2.popleft())
        p = pos[i[0]].pop()
        res[p] = i[0]
        l -= 1
    ml = cnt[0][1]
    remain = []
    
    while cnt:
        i, j = cnt.popleft()
        remain += [i] * j
    while cnt2:
        i, j =cnt2.popleft()
        remain += [i] * j
    if y - x > (len(remain) - ml) * 2 :
        print('No')
        continue
    i = 0
    match = [0] * len(remain)
    for i in range(ml, ml + y - x):
        match[i % len(remain)] = remain[(i + ml) % len(remain)]
    for i in range(ml + y - x, ml + len(remain)):
        match[i % len(remain)] = noin
    # print(match, remain)
    for i in range(len(match)):
        p = pos[remain[i]].pop()
        res[p] = match[i]
    
    if l == 0:
        print("YES")
        for i in res:
            print(i, end=' ')
        print()
    else:
        print("No")

    

    

