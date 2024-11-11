N,K,Q=map(int,input().split())
L=[K-Q]*N
for j in range(1,Q+1):
  A=int(input())
  L[A-1]+=1
for i in L:
  if i>0:
    print("Yes")
  else:
    print("No")
