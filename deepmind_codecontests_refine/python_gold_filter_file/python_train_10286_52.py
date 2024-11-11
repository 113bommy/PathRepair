n=int(input())
l=list(map(int,input().split()))
z=0
for i in range(n):
  if l[i]!=i+1:
    z+=1
if z<=2:
  print("YES")
else:
  print("NO")