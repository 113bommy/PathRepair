N=int(input())
CSF=[list(map(int,input().split())) for i in range(N-1)]
for i in range(N-1):
    ans=0
    for j in range(i,N-1):
        c,s,f=CSF[j]
        ans=max(s,ans+abs(ans%-f))
        ans+=c
    print(ans)
print(0)