import sys, math

input = lambda: sys.stdin.readline().rstrip()

for _ in range(int(input())):
    n, k = map(int, input().split())
    c = k
    b = list(map(int, input().split()))
    ans = True
    a = []
    for i in b:
        if i not in a:
            a.append(i)
            k -= 1
            if k < 0:
                ans = False
                break
    if k < 0:
        ans = False
    if ans:
        for i in range(k):
            a.append(1)
        print(n * (len(a)))
        for _ in range(n):
            print(*a,end=' ')
        print()
    else:
        print(-1)