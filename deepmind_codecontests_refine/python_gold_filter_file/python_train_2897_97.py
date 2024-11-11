n=int(input())
s=[[0] for _ in range(n)]
for i in range(n):
    s[i]=input()

ans=0
for p in range(n):
    cnt=0
    t=[[0] for _ in range(n)]
    for i in range(n):
        t[i]=s[(i+p)%n]
    for r in range(n):
        for l in range(n):
            if t[r][l]==t[l][r]:
                cnt+=1
    if cnt==n**2:
        ans+=1
print(ans*n)
