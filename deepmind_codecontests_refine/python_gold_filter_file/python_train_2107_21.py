from sys import stdin
input = stdin.readline

q = int(input())
for _ in range(q):
    n = int(input())
    t = [int(x) for x in input().split()]
    l = len(set(t))
    if l == 1:
        print(1)
        print(*([1]*n))
        continue
    if n % 2 == 0:
        print(2)
        print(*([1, 2] * (n // 2)))
        continue
    b = False
    for i in range(n-1):
        if t[i] == t[i+1]:
            b = True
            x = i+1
    if t[0] == t[n-1]:
        b = True
        x = 0
    if not b:
        print(3)
        print(*([1, 2] * (n // 2) + [3]))
        continue
    z = True
    ans = []
    for i in range(n):
        if i != x:
            z = not z
        ans.append(z + 1)
    print(2)
    print(*ans)