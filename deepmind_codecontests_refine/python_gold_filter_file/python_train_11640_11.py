n,*h=map(int,open(0).read().split())
for i in range(n-1)[::-1]:
  if h[i+1]<h[i]:
    h[i]-=1
    if h[i+1]<h[i]:
      print('No')
      exit()
print('Yes')