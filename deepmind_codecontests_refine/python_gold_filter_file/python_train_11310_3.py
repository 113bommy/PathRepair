n,m,k=map(int,input().split())
l=[[0]*m for i in range(n)]

for i in range(n):
    s=input()
    for j in range(m):
        if s[j]==".":
            l[i][j]=1
ans=0
for i in range(n):
    c=0
    for j in range(m):
        if l[i][j]:
            c+=1
            if c>=k:
                ans+=1
        else:
            c=0

for j in range(m):
    c=0
    for i in range(n):
        if l[i][j]:
            c+=1
            if c>=k:
                ans+=1
        else:
            c=0
if k==1:
    ans//=2
print(ans)