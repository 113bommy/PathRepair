n,m=map(int,input().split())
AC=[0]*n
cnt=[0]*n
ans=0
for i in range(m):
    p,s=input().split()
    p=int(p)
    s=str(s)
    if s=='WA' and AC[p-1]==0:
        cnt[p-1]+=1
    if s=='AC' and AC[p-1]==0:
        AC[p-1]=1
        ans+=cnt[p-1]
print(sum(AC),ans)