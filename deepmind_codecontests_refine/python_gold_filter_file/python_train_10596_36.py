N,K=map(int,input().split())
p=0
while N/K>=1:
  N=N/K
  p=p+1
print(p+1)