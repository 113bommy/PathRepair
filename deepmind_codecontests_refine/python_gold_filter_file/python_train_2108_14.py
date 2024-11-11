t = int(input())
sol = []
for tc in range(t):
  n = int(input())

  idx = 0
  for i in range(31):
    if 2**i > n:
      idx = i - 1
      break
  arr = [2**i for i in range(idx)]
  arr.append(n - (2**idx - 1))
  arr.sort()
  # print(sum(arr))
  
  diff = []
  for i in range(len(arr)-1):
    diff.append(arr[i+1] - arr[i])
  # print(diff)
  sol.append(diff)

for s in sol:
  print(len(s))
  print(*s)
  