n,m=map(int,input().split())
c=0

l = []
for i in range(n):
    l.append(input())

for i in range(n):
    for j in range(m):
        if l[i][j]!="W":
            continue
        for x,y in [(i,j+1),(i,j-1),(i+1,j),(i-1,j)]:
            if 0<=x<n and 0<=y<m and l[x][y]=='P':
                c+=1
                break
print(c)