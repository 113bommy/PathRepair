from collections import deque
t = int(input())
for i in range(t):
    n = int(input())
    sp = list(map(int, input().split()))
    indec = [0] * len(sp)
    indec[len(sp) - 1] = len(sp) - 1
    D = deque()
    D.append((sp[len(sp) - 1], len(sp) - 1))
    for i in range(len(sp) - 1, -1, -1):
        a = D.pop()
        k = False
        while a[0] >= sp[i]:
            if len(D) == 0:
                D.append((sp[i], i))
                indec[i] = i
                k = True
                break
            a = D.pop()
        if k != True:
            D.append(a)
            indec[i] = a[1]
    kol = 0
    for i in range(len(indec)):
        if indec[i] != i:
            kol += 1
    print(kol)
