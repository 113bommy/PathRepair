X,N=map(int, input().split())
if N==0:
  print(X)
  exit()
P=list(map(int, input().split()))  
ans=-1
for i in range(-1,102):
  if i not in P:
    if abs(X-i)<abs(X-ans):
      ans=i
print(ans)