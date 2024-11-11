def insertion_sort(a, g, cnt):
  for i in range(g, len(a)):
    v = a[i]
    j = i - g
    while j >= 0 and a[j] > v:
      a[j+g] = a[j]
      j = j - g
      cnt += 1
    a[j+g] = v
  return cnt

n = int(input())
g = [1]
t = 1
cnt = 0
while 1:
  t = 3 * t + 1
  if t < n and len(g) < 100:
    g += [t]
  else:
    g = g[::-1]
    break
a = [int(input()) for _ in range(n)]
for i in range(0, len(g)):
  cnt = insertion_sort(a, g[i], cnt)
print(len(g))
print(*g)
print(cnt)
for i in a: print(i)
