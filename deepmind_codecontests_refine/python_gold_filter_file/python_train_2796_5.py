n,x=map(int,input().split())
if n==2:
  if x==2:
    print("Yes",1,2,3,sep="\n")
    exit()
  else:
    print("No")
    exit()
if x==1 or x==n*2-1:
  print("No")
  exit()
ans=[i for i in range(1,2*n)]
for i in range(len(ans)):
  ans[i]=(ans[i]-(n-x+1))%(2*n-1)+1
print("Yes",*ans,sep="\n")