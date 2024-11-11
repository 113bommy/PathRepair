n, k = map(int, input().split())
a = list(map(int, input().split()))
for j in range(min(k, 41)):
  b = [0]*n
  for i in range(n):
    l = max(0, i-a[i])
    r = min(n, i+a[i]+1)
    b[l] += 1
    if r < n:
      b[r] -= 1
  for i in range(1, n): 
    b[i]+=b[i-1]
  a = b

print(" ".join(list(map(str, a))))
      
  
