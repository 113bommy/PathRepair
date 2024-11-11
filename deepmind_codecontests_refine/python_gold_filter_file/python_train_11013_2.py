n,k,q=map(int,input().split())
A=[0]*n
for i in range(q):
  A[int(input())-1]+=1
for i in range(n):
  if k-q+A[i]<=0:
    print("No")
  else:
    print("Yes")

