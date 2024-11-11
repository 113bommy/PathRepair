t = int(input())
mod = 10**9+7
for _ in range(t):
    n,c = input().split()
    n = int(n)
    s = input()
    if s== c*n:
        print(0)
        continue
    ci = n-1
    while ci>=0 and s[ci]!=c:
        ci-=1
    if ci==-1:
        print(2)
        print(n,n-1)
    else:
        if ci*2+2<=n:
            print(2)
            print(n,n-1)
        else:
            print(1)
            print(ci+1)
