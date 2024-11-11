from queue import Queue

t = int(input())
for pp in range(t):
    n = int(input())
    l, r = list(), list()
    for i in range(n):
        x, y = map(int, input().split())
        l.append(x)
        r.append(y)
    ans = [-1] * n
    t = 1
    i = 0
    q = Queue()
    while i < n or (not q.empty()):
        while i < n and l[i] <= t:
            q.put(i)
            i += 1
        f = True
        while f:
            if q.empty():
                f = False
            else:
                si = q.get()
                if t <= r[si]:
                    f = False
                    ans[si] = t
                else:
                    ans[si] = 0
        t += 1
    print(" ".join(map(str, ans)))
                
            