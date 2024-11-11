n, k = map(int, input().split())
A = list(map(int, input().split()))
F = list(map(int, input().split()))
A.sort()
F.sort(reverse=True)
l = -1
r = 10 ** 13
while r - l > 1:
  m = (l + r) // 2
  if sum([(a - m // f) if a * f > m else 0 for a, f in zip(A, F)]) <= k:
    r = m
  else:
    l = m
    
print(r)