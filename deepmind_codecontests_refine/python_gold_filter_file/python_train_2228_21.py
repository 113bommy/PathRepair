n,m = map(int, input().split())
f = list(map(int, input().split()))

f = sorted(f)

count = 0

l = 0
r = n-1
min_diff = 99999
while r < m:
  if f[l] and f[r] and abs(f[l]-f[r]) < min_diff:
    min_diff = abs(f[l]-f[r])
    l += 1
    r += 1
  else:
    l += 1
    r += 1

print(min_diff)