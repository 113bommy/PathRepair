x,n=map(int,input().split())
r=[i-x for i in map(int,input().split())]
for i in range(n+1):
  if not -(i) in r:
    print(x-i)
    break
  elif not i in r:
    print(x+i)
    break
