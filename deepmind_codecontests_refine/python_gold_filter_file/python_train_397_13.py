H,W,K=map(int,input().split())
A=[input() for i in range(H)]
for i,l in enumerate(A):
    if 'S' in l:
        S=(K,i,l.index('S'))
from collections import deque
q=deque([S])
X=[(S[1],S[2])]
n=((0,1),(0,-1),(1,0),(-1,0))
v=[[0]*W for i in range(H)]
v[S[1]][S[2]]=1
while q:
    m,i,j=q.popleft()
    for x,y in n:
        if 0<=i+x<H and 0<=j+y<W:
            if v[i+x][j+y]:continue
            v[i+x][j+y]=1
            if A[i+x][j+y]=='.' and m>0:
                q.append((m-1,i+x,j+y))
                X.append((i+x,j+y))
print(min([min(0--i//K,0--(H-i-1)//K,0--j//K,0--(W-j-1)//K) for i,j in X])+1)