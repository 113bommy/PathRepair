N=int(input())
T=list(map(int,input().split()))
M=int(input())
Ans=sum(T)
for i in range(M):
  p,x=map(int,input().split())
  xx=Ans+x-T[p-1]
  print(xx)
