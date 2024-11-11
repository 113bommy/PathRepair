t = int(input())

for test in range(t):
  n, k = map(int, input().split())
  poss = list(map(int, input().split()))
  
  res = max(poss[0], n - poss[-1] + 1)
  for i in range(1, k):
    res = max(res, (poss[i] - poss[i - 1] + 2) // 2)
  print(res)
