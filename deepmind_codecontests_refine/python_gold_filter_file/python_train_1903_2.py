from collections import deque

h = int(input())
l = []
for i in range(h):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    p = []
    queue = deque
    s = []
    n = 0
    d = 0
    for j in a:
        n += j
        p.append(n)
    for j in range(len(a)):
        if b[j] == 0:
            s.append(a[j])
    s.sort()
    for i in range(len(a)):
        if b[i] == 0:
            a[i] = s.pop()
    for j in a:
        print(j, end=" ")

    print()