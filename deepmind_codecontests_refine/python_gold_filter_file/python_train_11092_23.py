n=int(input())
s=list(input())
l=list(map(int,input().split()))
ans=11**11
for i in range(n-1):
    if s[i]=='R' and s[i+1]=='L':
        t=(l[i+1]-l[i])//2
        if ans>t: ans=t
if ans==11**11: print(-1)
else: print(ans)