n = int(input())
b = list(map(int,input().split()))
a = list(map(int,input().split()))
lock = [0]*n

ans = 0
top = []
for i in range(n):
  if a[i] < b[i]:
    print(-1)
    exit()
  if a[i] == b[i]:
    lock[i] = 1
    continue
  if a[i-1]+a[(i+1)%n]<a[i]:
    top.append(i)
while True:
  while top:
    x = top.pop()
    ne = a[x-1]+a[(x+1)%n]
    if (a[x]-b[x])%ne == 0:
      ans += (a[x]-b[x])//ne
      lock[x] = 1
      a[x] = b[x]
    else:
      ans += a[x]//ne
      a[x] %= ne
    for i in (x+1,x-1):
      if a[i-1]+a[(i+1)%n]<a[i%n]:
        top.append(i%n)
  if lock.count(1) == n:
    print(ans)
    exit()
  elif not top:
    print(-1)
    exit()