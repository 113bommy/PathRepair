n, k = map(int, input().split())
v = list(map(int, input().split()))
ans = 0
for a in range(min(n, k)+1):
  for b in range(min(n, k)-a+1):
    bag = []
    bag += v[:a]
    bag += v[len(v)-b:]
    bag.sort()
    if len(bag) > 0:
      for c in range(k-a-b):
        if bag[0] < 0:
          bag.pop(0)
        if len(bag) == 0:
          break
    ans = max(ans, sum(bag))
      
print(ans)