n=int(input())
l=list(map(int,input().split()))
a=0
for i in range(n):
  if l[i]!=i+1:
    a+=1
if a==0 or a==2:
  print("YES")
else:
  print("NO")