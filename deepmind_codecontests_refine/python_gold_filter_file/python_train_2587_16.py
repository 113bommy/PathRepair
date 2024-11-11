K,S=map(int,input().split())
points=0
for i in range(K+1):
  for j in range(K+1):
    if 0<=S-i-j<=K:
      points+=1
print(points)
