N,K=map(int,input().split())
V=list(map(int,input().split()))
ans=0
for i in range(N):
    for j in range(i,N+1):
        if i+N-j<=K:
            k=K-(i+N-j)
            s=V[:i]+V[j:]
            s.sort()
            c=0
            for t in s:
                if k>=1 and t<0:
                    k-=1
                else:
                    c+=t
            ans=max(c,ans)
print(ans)
