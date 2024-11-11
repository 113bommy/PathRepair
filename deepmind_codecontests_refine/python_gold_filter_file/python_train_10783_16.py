n,m = map(int,input().split())
if n<=m: print(n)
else:
    l,r = 0,int(2e9)
    while l<r:
        mi = (l+r)//2
        val = mi*(mi+1)//2
        if n-val<=m: r=mi
        else: l=mi+1
    print(l+m)