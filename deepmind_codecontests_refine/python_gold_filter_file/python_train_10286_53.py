n=int(input())
p=list(map(int,input().split()))
cnt=0
for i in range(n):
  if p[i]==i+1:
    cnt += 1
if cnt < n-2:
  print("NO")
else:
  print("YES")