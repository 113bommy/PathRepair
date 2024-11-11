N,K=map(int,input().split())
a=list(map(int,input().split()))
for v in range(N-K):
  if a[v]>=a[K+v]:
    print("No")
  else:
    print("Yes")
