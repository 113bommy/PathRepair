N,X=map(int,input().split())
M=[0]*N
for i in range(N):
  M[i]=int(input())

print(N+(X-sum(M))//min(M))