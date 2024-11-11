K,S=map(int,input().split())
point=0
for i in range(K+1):
  for j in range(K+1):
    if 0<=S-i-j<=K:
      point+=1
print(point)