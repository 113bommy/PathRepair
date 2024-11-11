t=int(input())
for i in range(t):
  n=int(input())
  a=[int(i) for i in input().split()]
  b=sum([a[i] for i in range(0,n,2)])
  c=sum([a[i] for i in range(1,n,2)])
  if b==c:
    if b==0:
      print(n//2)
      print(*[0 for i in range(n//2)])
    else:
      print(n)
      print(*a)
  elif a.count(0)<n//2:
    b=[int(i) for i in a if i!=0]
    if len(b)%2!=0:
      print(max(len(b)-1,1))
      if max(len(b)-1,1)==1:
        print(0)
      else:
        print(*b[1:])
    else:
      print(len(b))
      print(*b)
  else:
      print(a.count(0))
      print(*[0 for i in range(a.count(0))])