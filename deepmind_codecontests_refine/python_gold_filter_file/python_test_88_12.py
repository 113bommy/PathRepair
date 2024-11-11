t=int(input())
for _ in range(t):
  n=int(input())
  a=list(map(int,input().split()))
  ans='NO'
  if n%2==0:
    ans='YES'
  for i in range(n-1):
    if a[i]>=a[i+1]:
      ans='YES'
  print(ans)