N=int(input())
a=list(map(int,input().split()))
b=[0]*N
sum=0
for i in range(N):
  b[a[i]-1]+=1

for i in range(N):
  sum+=b[i]*(b[i]-1)//2
for i in range(N):
  print(sum-b[a[i]-1]+1)