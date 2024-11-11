n,m=[int(x) for x in input().split()]
v=[input().strip() for _ in range(n)]
ans=True
for i in range(n):
    for j in range(m):
        if v[i][j]=='*': continue
        r=0
        for u in range(i-1,i+2):
            for w in range(j-1,j+2):
                if u<0 or u>=n or w<0 or w>=m: continue
                if v[u][w]=='*': r+=1
        if r==0 and v[i][j]!='.': ans=False
        if r>0 and v[i][j]!=chr(ord('0')+r): ans=False
print("YES" if ans else "NO")