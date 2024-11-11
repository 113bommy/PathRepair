import bisect
n,k = map(int,input().split())
v = list(map(int,input().split()))
prefix = [0 for _ in range(n+1)]
suff = [0 for _ in range(n+1)]
pref = [0 for _ in range(n+1)]
zero = [0 for _ in range(n+1)]
for i in range(0,n):
  if v[i] == 0 : 
    zero[i+1] = 1 + zero[i]
    prefix[i+1] = prefix[i]
  else :
    zero[i+1] = zero[i]
    prefix[i+1] = 1 + prefix[i] 
for i in range(0,n) : 
  if v[i] == 1 : pref[i+1] = 1 + pref[i]
for i in range(n-1, -1, -1) :
  if v[i] == 1 : suff[i] = 1 + suff[i+1] 
l = r = -1 ; mxm = max(pref)
if k == 0 : 
  print(max(pref))
  print(*v)
  exit()
for i in range(0,n) : 
  if v[i] == 0 :
    index = bisect.bisect_left(zero,k + zero[i],0,n+1,)
    if index >= n+1 : index -= 1
    x = y = z = 0
    x = pref[i]
    y = prefix[index] - prefix[i]
    if index< n+1 : z = suff[index]
    sum = zero[index] - zero[i] + x + y + z
    if mxm < sum : 
      mxm = sum
      l = i
      r = index - 1
for i in range(l, r+1) : 
  if v[i] == 0 : v[i] = 1
print(mxm)
print(*v)


    
