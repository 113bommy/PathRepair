r,g=map(int,input().split())
X=0
for i in range(r+1):
  for j in range(r+1):
    k=g-i-j
    if k>=0 and k<=r:
      X+=1
print(X)
