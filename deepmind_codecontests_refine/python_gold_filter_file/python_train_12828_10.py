t = int(input())
for _ in range(t):
  n, a, b = map(int, input().split())
  print(min(max(a+b-n+1, 1), n), min(a+b-1, n))