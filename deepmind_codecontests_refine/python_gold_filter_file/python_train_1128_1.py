n = int(input())
a = list(map(int, input().split()))

p = set()
q = 0
for i in range(n):
  if a[i] < 3200:
    p.add(a[i]//400)
  else:
    q += 1

p = len(p)
print(max(p, 1), p+q)