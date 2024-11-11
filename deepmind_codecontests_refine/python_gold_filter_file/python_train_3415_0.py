n,l=map(int,input().split())

if l <= 0:
  if -1 * l >= n:
    n -= 1
else:
  l += 1
  n -= 1

print(int(n*(2*l+n-1)/2))