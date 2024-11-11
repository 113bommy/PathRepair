n=int(input())
d=list(map(int,input().split()))
sm=0
for i in range(n):
  for j in range(i+1,n):
    sm+=d[i]*d[j]
print(sm)