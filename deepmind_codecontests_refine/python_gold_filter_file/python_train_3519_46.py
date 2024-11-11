n, k = map(int, input().split())
v = list(map(int, input().split()))
mini = min(n, k)
value = 0
for a in range(mini + 1):
  for b in range(mini - a + 1):
    c = k - a - b
    j = v[:a] + v[n-b:]
    j.sort(reverse=True)
    for _ in range(c):
      if j and j[-1] < 0:
        j.pop()
      else:
        break
    value = max(value, sum(j))
print(value)