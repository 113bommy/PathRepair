def patty(n,x):
  if n == 0:
    if x <= 0:
      return 0
    else: 
      return 1
  elif x <= 1 + a[n-1]:
    return patty(n-1, x-1)
  else:
    return p[n-1] + 1 + patty(n-1, x-2-a[n-1])

n,x = map(int, input().split())
a = [1]
p = [1]
for i in range(n):
  a.append(a[i] * 2 + 3)
  p.append(p[i] * 2 + 1)
ans = patty(n,x)
print(ans)