n = int(input())
a = list(map(int, input().split()))
m = 0
id = -1
for i in range(n):
  if abs(a[i]) >= abs(m):
    m = a[i]
    id = i
ope = []
for i in range(n):
  a[i] += m
  ope.append([id+1, i+1])
if m >= 0:
  for i in range(1, n):
    a[i] += a[i-1]
    ope.append([i, i+1])
else:
  for i in range(1, n):
    a[n-i-1] += a[n-i]
    ope.append([n-i+1, n-i])
print(len(ope))
for x in ope:
  print(x[0], x[1])