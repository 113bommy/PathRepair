t = int(input())
for _ in range(t):
    n = int(input())
    if n < 4:
        print(-1)
    else:
        x = list(range(1,n+1,1))
        p = []
        np = []
        y = [2, 4, 1, 3]
        for i in range(n):
            if x[i]%2 == 0:
                p.append(x[i])
            else:
                np.append(x[i])
        del p[0:2]
        del np[0:2]
        np.sort(reverse=True)
        y.extend(p)
        y = np + y
        print(*y)