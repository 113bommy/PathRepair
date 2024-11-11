N,K=map(int,input().split())
V=list(map(int,input().split()))
r,ans=min(N,K),0
for a in range(r+1):
  for b in range(r-a+1):
    tmp,minus=0,[]
    for i in range(a):
      tmp+=V[i]
      if V[i]<0:
        minus.append(V[i])
    for j in range(b):
      tmp+=V[N-j-1]
      if V[N-j-1]<0:
        minus.append(V[N-j-1])
    tmp-=sum(sorted(minus)[:K-(a+b)])
    ans=max(ans,tmp)
print(ans)