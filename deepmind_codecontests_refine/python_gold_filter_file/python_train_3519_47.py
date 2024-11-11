n,k=map(int,input().split())
V=list(map(int,input().split()))
ans=0
for i in range(n+1):
    for j in range(n-i+1):
        if i+j>k:
            continue
        tmp=V[:i]+V[n-j:]
        tmp.sort(reverse=True)
        for l in range(k-i-j):
            if tmp and tmp[-1]<0:
                tmp.pop()
            else:
                break
        ans=max(ans,sum(tmp))
print(ans)