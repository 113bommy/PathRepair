n,x,y=map(int,input().split())
x-=1 ; y-=1
A=[0 for i in range(n+8)]

for i in range(n):
  for j in range(i):
    A[min(i-j, abs(i-y)+1+abs(j-x))]+=1
for i in range(1,n):
  print(A[i])
