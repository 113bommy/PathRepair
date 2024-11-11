from itertools import accumulate
n,k = map(int,input().split())
a = list(map(int,input().split()))
a.sort()
acc = list(accumulate(a))

def maxsum(ls,k):
  l = len(ls)
  if l==0:
    return 0
  dp = [0 for i in range(l+1)]
  dp[0] = 1
  for i in range(1,l+1):
    dp[i] = (dp[i-1]|(dp[i-1]<<ls[i-1]))&((1<<k)-1)
  for b in range(k-1,-1,-1):
    if dp[l] & 1<<b:
      return b

for i in range(n):
  if a[i]>=k:
    a = a[:i]
    break
n = len(a)
if acc[n-1] < k:
  print(n)
  exit()
sepa=[]
for i in range(n-1):
  if acc[i]<a[i+1]:
    sepa.append(i)
m=len(sepa)
if m==0:
  print(0)
  exit()
lf = 0
r = m-1
while lf<r:
  mid = (lf+r)//2
  x=sepa[mid]
  sumx = acc[x]
  if maxsum(a[x+1:],k)+sumx >= k:
    r = mid
  else:
    lf = mid+1
if r==0:
  t=sepa[0]
  if maxsum(a[t+1:],k)+acc[t]>=k:
    print(0)
  else:
    print(sepa[r]+1)
else:
  print(sepa[r]+1)
