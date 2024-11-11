X, N = map(int, input().split())
A = list(map(int, input().split()))
a = 0
while True:
  if X-a not in A:
      print(X-a)
      break
  if X+a not in A:
      print(X+a)
      break
  a += 1