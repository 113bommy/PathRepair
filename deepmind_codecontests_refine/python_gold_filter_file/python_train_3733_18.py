N=int(input())
T=list(map(int,input().split()))
M=int(input())
ans=sum(T)
for _ in range(M):
  P,X=map(int,input().split())
  print(ans-T[P-1]+X)