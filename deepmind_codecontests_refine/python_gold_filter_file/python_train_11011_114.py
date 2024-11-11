N,K=map(int,input().split())
light=list(map(int,input().split()))
for k in range(K):
  imo=[0]*(N+1)
  for i in range(N):
    l=max(0,i-light[i])
    r=min(N-1,i+light[i])+1
    imo[l]+=1
    imo[r]-=1
  for i in range(1,N):
    imo[i]+=imo[i-1]
  if light==imo:
    break
  else:
    light=imo[:]
print(*light[:-1])