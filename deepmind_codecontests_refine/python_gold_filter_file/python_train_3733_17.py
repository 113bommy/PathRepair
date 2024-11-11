N=int(input())
T=list(map(int,input().split()))
T_ALL=sum(T)
M=int(input())

for i in range(M):
  P,X=map(int,input().split())
  ans=T_ALL+X-T[P-1]
  print(ans)
