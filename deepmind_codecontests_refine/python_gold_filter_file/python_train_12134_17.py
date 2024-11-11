n=int(input().strip())
a=[int(i) for i in input().strip().split()]
if n==1:
  print(1)
else:
  l=[-1]
  for i in range(n-1):
    if a[i]>=a[i+1]:
      l.append(i)
  l=l+[n-1]
  ans=0
  for i in range(len(l)-1):
    ans=max(ans,l[i+1]-l[i])
  print(ans)