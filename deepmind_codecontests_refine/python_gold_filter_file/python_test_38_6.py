import sys
input = sys.stdin.readline
I = lambda :  list(map(int,input().split()))

t=1
for _ in range(t):
    n,m = I()
    grid = [list(input().strip()) for i in range(n)]
    ans = [0]*(m+1)
    for j in range(m-1):
        for i in range(1,n):
            if grid[i][j] + grid[i-1][j+1]=="XX":
                ans[j]=1
                break
    for i in range(1,m):
        ans[i]+=ans[i-1]
    ans[-1] = 0
    q,=I()
    for i in range(q):
        l,r = I()
        an = "YES"
        if r>l:
            cnt = ans[r-2]-ans[l-2]
            #print(l,r,cnt)
            if cnt:
                an="NO"
        print(an)
    