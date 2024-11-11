N,K=map(int,input().split())
V=list(map(int,input().split()))

ans=0
for nab in range(1,min(N+1,K+1)):
    nr=K-nab
    for na in range(nab+1):
        nb=nab-na
        vt=sorted(V[:na]+V[N-nb:])
        for ncd in range(min(nr+1,nab+1)):
            np=sum(vt[ncd:])
            ans=max(ans,np)

print(ans)
            
