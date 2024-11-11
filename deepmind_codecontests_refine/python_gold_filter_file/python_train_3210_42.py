a,b,k=map(int,input().split())
l=range(a,b+1)
ans=sorted(set(l[:k])|set(l[-k:]))
for i in ans:
    print(i)