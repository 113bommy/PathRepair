t = int(input())
for _ in range(t):
  n, s, k = map(int, input().split())
  ngs = set(map(int, input().split()))
  ans = 10**9
  for i in range(max(1, s - k - 1), min(n + 1, s + k + 2)):
    if i not in ngs and abs(i - s) < ans:
      ans = abs(i - s)
  print(ans)
