n=int(input())
cnt=0
for i in range(n):
  a,b=map(int,input().split())
  if a==b:
    cnt+=1
    if cnt==3:
      print("Yes")
      break
  else:
    cnt=0
else:
  print("No")