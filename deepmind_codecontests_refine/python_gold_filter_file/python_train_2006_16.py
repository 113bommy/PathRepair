t = int(input())
for i in range(t):
  n, k = map(int, input().split())
  if n < k:
    print(abs(n - k))
  elif (n + k) % 2:
    print(1)
  else:
    print(0) 
