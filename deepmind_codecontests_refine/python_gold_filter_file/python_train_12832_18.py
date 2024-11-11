for _ in range(int(input())):
    n = int(input())
    a = list(map(int,input().split()))
    mn = min(a)
    mx = max(a)
    ans = 0
    d = {}
    for i in a:
        d[i] = d.get(i,0) + 1 
    p = d.copy()
    for s in range(mn+mn,mx+mx+1):
        cnt = 0
        for i in range(n):
            if((s - a[i]) in p.keys()):
                if(s-a[i] != a[i]):
                    ocnt = min(p[s-a[i]] , p[a[i]])
                    p[a[i]] -= ocnt 
                    p[s-a[i]] -= ocnt
                else:
                    ocnt = p[s-a[i]]//2
                    p[a[i]] = p[a[i]]%2
                cnt += ocnt 
        ans = max(ans,cnt)
        p = d.copy()
    print(ans)