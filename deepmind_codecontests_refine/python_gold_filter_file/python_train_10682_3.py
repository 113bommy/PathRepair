n,k,t = map(int, input().split())
q=0
if t <= n and  t >= k: print(k);q+=1 
if t < k :print(t);q+=1
if q == 0:print(k - (t-n))