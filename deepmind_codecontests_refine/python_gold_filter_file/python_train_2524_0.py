t = int(input())
while t>0:
    n,x = map(int,input().split())
    a = list(map(int,input().split()))
    c = 0
    for i in a:
        if i%x != 0:
            c = 1
            break
    if c:
        s = 0
        for i in a:
            s += i
        if s % x != 0:
            print(n)
        else:
            for i in range(0,n):
                if a[i] % x != 0:
                    l = i
                    break
            for i in range(n-1,-1,-1):
                if a[i] % x != 0:
                    r = i
                    break
            ans = max(r,n-l-1)
            print(ans)
    else:
        print(-1)
    t -= 1