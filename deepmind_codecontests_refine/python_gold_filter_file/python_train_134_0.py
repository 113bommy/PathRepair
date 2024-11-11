t = int(input())
for _ in range(t):
    input()
    k, n, m = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    seq = []
    ns = 0
    ms = 0
    while(ns != n or ms != m):
        temp = 0
        while(ns < n and (a[ns] == 0 or a[ns] <= k)):
            temp = 1
            if(a[ns] == 0):
                k += 1
            seq.append(a[ns])
            ns += 1
        while(ms < m and (b[ms] == 0 or b[ms] <= k)):
            temp = 1
            if(b[ms] == 0):
                k += 1
            seq.append(b[ms])
            ms += 1
        if(temp == 0):
            break 
    if(len(seq) == m+n):
        print(*seq)
    else:
        print(-1)
