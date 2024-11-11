t=int(input())
for i in range(t):
  n,m=map(int, input().split())
  a=[int (i) for i in input().split()]
  if m<n or n==2:
    print(-1)
  else:
    x1=min(a)
    x=a.index(x1)
    a[x]+=10001
    y1=min(a)
    y=a.index(y1)
    a[x]-=10001
    print(2*sum(a)+(m-n)*(x1+y1))
    for i in range(1, n):
      print(i, i+1)
    print(1, n)
    for i in range(m-n):
      print(x+1, y+1)  