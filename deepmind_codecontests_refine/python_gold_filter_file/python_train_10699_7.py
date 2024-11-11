for _ in range(int(input())):
  n=int(input())
  a=list(map(int,input().split()))
  s=input()
  b=[]
  ans=0
  for i in range(n-1,-1,-1):
    for j in b:
      a[i]=min(a[i],a[i]^j)
    if a[i]!=0:
      if s[i]=="0":
        b.append(a[i])
      else:
        ans=1
  print(ans)