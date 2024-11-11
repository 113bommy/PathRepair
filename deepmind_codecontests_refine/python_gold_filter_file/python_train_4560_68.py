n, k = map(int, input().split())
a = list(map(int, input().split()))
f = list(map(int, input().split()))

a.sort()
f.sort(reverse=True)

l = -1
r = 10**12

while l+1 < r:
  c = (l+r)//2
  s = 0
  for i in range(n):
    s += max(0, a[i] - c//f[i])
  if s <= k:
    r = c
  else:
    l = c
print(r)
