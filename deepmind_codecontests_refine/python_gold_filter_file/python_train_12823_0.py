t = int(input())
for i in range(t):
    n, m = [int(item) for item in input().split()]
    mat = []
    col = [[] for _ in range(m)]
    for j in range(n):
        line = [int(item) for item in input().split()]
        for k, item in enumerate(line):
            col[k].append(item)
        mat.append(line)
    colmax = []
    for line in col:
        colmax.append([max(line), line])
    colmax.sort(reverse=True)
    colmax = colmax[:n]
    ans = 0
    for j in range(n ** (n-1)):
        index = j
        rot = [0]
        for k in range(n-1):
            rot.append(index % n)
            index //= n 
        ret = 0
        for l in range(n):
            val = 0
            for k in range(len(colmax)):
                val = max(val, colmax[k][1][(l + rot[k]) % n])
            ret += val
        ans = max(ans, ret)
    print(ans)