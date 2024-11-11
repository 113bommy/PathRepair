N=int(input())
d=list(map(int,input().split()))
a=0
for i in range(N):
  for j in range(i+1,N):
    a+=d[i]*d[j]
print(a)