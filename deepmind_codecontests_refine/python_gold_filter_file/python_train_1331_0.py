H,W=map(int,input().split())
s=[input() for _  in range(H)]
G=[["#"]*(W+2) for _ in range(H+2)]

for i in range(H):
    for j in range(W):
        G[i+1][j+1]=s[i][j]

def search(y,x):
    q=[(y,x)]
    d=[[-1]*(W+2) for _ in range(H+2)]
    d[y][x]=0
    while q:
        y1,x1=q.pop(0)
        for y2,x2 in ((y1+1,x1),(y1,x1+1),(y1-1,x1),(y1,x1-1)):
            if G[y2][x2]=="." and d[y2][x2]==-1:
                d[y2][x2]=d[y1][x1]+1
                q.append((y2,x2))
    return max(max(_) for _ in d)

ans=0
for i in range(H):
    for j in range(W):
        if G[i+1][j+1]==".":
            ans=max(search(i+1,j+1),ans)

print(ans)