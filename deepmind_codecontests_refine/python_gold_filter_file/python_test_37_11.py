T=int(input())
for i in range(T):
  N,M=map(int,input().split())
  S=set(range(N))
  for j in range(M):
    a,b,c=map(int,input().split())
    a-=1
    b-=1
    c-=1
    if b in S:
      S.remove(b)
  k=list(S)[0]
  for j in range(N):
    if j==k:
      continue
    else:
      print(j+1,k+1)