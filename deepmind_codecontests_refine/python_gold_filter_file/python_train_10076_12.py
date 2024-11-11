N=int(input())
P=list(map(int,input().split()))

m=P[0]
c=0
for i in range(N):
  if P[i]<=m:
    c+=1
  m=min(m,P[i])
  
print(c)