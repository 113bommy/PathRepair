t=int(input())
for i in range(t):
  n=int(input())
  x=[int(x) for x in input().split()]
  if x[0]+x[1]<=x[n-1]:
    print(1, 2, n)
  else:
    print(-1)