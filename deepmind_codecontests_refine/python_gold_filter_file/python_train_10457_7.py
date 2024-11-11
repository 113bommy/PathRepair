k,a,b=map(int,input().split())
s=input()
n=len(s)
if not a*k<=n<=b*k:
  print("No solution")
  exit()
ans=[]
for i in range(a,b+1):
  if a*(k-1)<=i*(k-1)<=b*(k-1):
    rest=n-i*(k-1)
    if a<=rest<=b:
      for j in range(k-1):
        ans.append(s[i*j:i*(j+1)])
      ans.append(s[i*(k-1):])
      break
if len(ans)==0:
  print("No solution")
else:
  print(*ans,sep="\n")