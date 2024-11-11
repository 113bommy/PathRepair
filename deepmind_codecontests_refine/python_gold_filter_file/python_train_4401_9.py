for _ in range(int(input())):
  n=int(input())
  arr=list(map(int,input().split()))
  c=1
  ma=0
  for i in range(n-1):
    if arr[i]==arr[i+1]:
      c+=1
    else:
      ma=max(c,ma)
      c=1
  ma = max(c, ma)
  if ma!=n:
    print(1)
  else:
    print(n)










