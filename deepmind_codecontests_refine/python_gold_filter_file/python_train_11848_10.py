N=int(input())
p=list(map(int,input().split()))
q=list(map(int,input().split()))
ans=0
r=0
for i in range(N):
  if q[i]+r>p[i]:
    ans+=p[i]
    r=min(q[i]+r-p[i],q[i])
  else:
    ans+=q[i]+r
    r=0
ans+=min(p[N],r)
print(ans)
