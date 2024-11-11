def iinput():
    return [int(i) for i in input().split()]
 
 
inf = 10 ** 5 + 1
 
t = int(input())
for _ in range(t):
    n = int(input())
    a = iinput()
    l = iinput()
    ans = [0 for i in range(n)]
    for i in range(n):
        if l[i] == 1:
            ans[i] = a[i]
            a[i] = -inf
    for i in range(n):
        if not l[i]:
            ans[i] = max(a)
            a[a.index(max(a))] = -inf
    print(*ans)