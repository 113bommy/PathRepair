n,m = [int(i) for i in input().split()]
a = []
for i in range(n):
    a.append(input())
ans=0
for i in range(n):
    for j in range(m):
        if a[i][j]!='W': continue
        for x,y in ((i+1,j),(i-1,j),(i,j+1),(i,j-1)):
            if 0<=x<n and 0<=y<m and a[x][y] == 'P': ans+=1; break

print(ans)
