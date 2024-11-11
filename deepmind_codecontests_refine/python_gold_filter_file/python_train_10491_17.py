import sys
 
n, k = map(int, input().split())
a = [int(x) for x in input().split()]
mod = pow(10, 9)+7
zero = 0
plus = []
minus = []
for i in range(n):
  if a[i] == 0:
    zero += 1
  elif a[i] > 0:
    plus.append(a[i])
  else:
    minus.append(a[i])
 
P, M = len(plus), len(minus)
plus.sort(reverse=True)
minus.sort()
ans = 1
if n == k:
  for i in range(n):
    ans *= a[i]
    ans %= mod
elif P+M < k:
  ans = 0
elif P == 0:
  if zero >= 1 and k%2 == 1:
    ans = 0
  else:
    if k%2 == 1:
      minus.reverse()
    for i in range(k):
      ans *= minus[i]
      ans %= mod
else:
  q = 0
  if k%2:
    ans *= plus[0]
    ans %= mod
    q = 1
  judge = []
  for i in range((len(plus)-q)//2):
    judge.append(plus[2*i+q]*plus[2*i+q+1])
  for i in range(len(minus)//2):
    judge.append(minus[2*i]*minus[2*i+1])
  judge.sort(reverse=True)
  for i in range(k//2):
    ans *= (judge[i]%mod)
    ans %= mod
 
print(ans)