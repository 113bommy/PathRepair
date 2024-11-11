t=int(input())

for _ in range(t):
    n,m=map(int,input().split())
    grid=[]
    for __ in range(n):
        grid.append(list(map(int,input().split())))
    bad=False
    for i in range(n):
        for j in range(m):
            nbors=4
            if i==0 or i==n-1:
                nbors-=1
            if j==0 or j==m-1:
                nbors-=1
            if grid[i][j]>nbors:
                bad=True
        if bad:
            break
    if bad:
        print("NO")
        continue
    else:
        print("YES")
        print(2,*([3]*(m-2)),2)
        for _ in range(n-2):
            print(3,*([4]*(m-2)),3)
        print(2,*([3]*(m-2)),2)
            