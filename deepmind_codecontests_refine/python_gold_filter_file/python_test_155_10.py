for _ in range(int(input())):
    n= int(input())
    A = list(map(int,input().split()))
    s = input()
    d ={}
    for i in range(n):
        d[A[i]] = s[i]
        
    l = sorted(list(d.keys()))
    c0 = s.count('0')
    c1 = s.count('1')
    if c1==0 or c0==0:
        print(*A)
    else:
        st0,st1 = 1,c0+1
        g = 1
        ans = {}
        for i in l:
            if d[i] == '1':
                ans[g] = st1
                st1 += 1
            else:
                ans[g] = st0
                st0 += 1
            g += 1
        out = []
        for i in A:
            k = ans[i]
            out.append(k)
        print(*out)