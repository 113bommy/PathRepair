A,B=map(int,input().split())
K=0
M=1
while M<B:
  K+=1
  M+=A-1
print(K)
