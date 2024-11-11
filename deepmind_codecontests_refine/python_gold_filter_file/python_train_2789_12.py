n=int(input())
d=list(map(int,input().split()))
a=0
for i in range(n-1):
  for j in range(i+1,n):
    a+=d[i]*d[j]
print(a)