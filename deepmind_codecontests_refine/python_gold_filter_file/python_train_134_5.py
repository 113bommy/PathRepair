for _ in range(int(input())):
  n=input()
  k,n,m=map(int,input().split())
  x=list(map(int,input().split()))
  y=list(map(int,input().split()))
  i=0
  j = 0
  ans=[]
  while True:
    if i<n and x[i]<=k:
      if x[i]==0:
        k+=1
      ans.append(x[i])
      i+=1
    elif j<m and y[j]<=k:
      if y[j]==0:
        k+=1
      ans.append(y[j])
      j+=1
    else:
      break
  
  if i<n or j<m:
    ans=[-1]
  for i in ans:
    print(i, end = ' ')