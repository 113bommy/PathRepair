t = int(input())

for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    
    l = set(a)
    s = sorted(list(i for i in range(1, 1+n) if i not in l))[::-1]
    ar = a.copy()
    ok = True
    
    for i in range(1, n):
        if a[i] == a[i-1]:
            e = s.pop()
            if a[i] < e:
                ok = False
                break
            else:
                ar[i] = e
                
    if ok:
        print(*ar)
    else:
        print(-1)
            