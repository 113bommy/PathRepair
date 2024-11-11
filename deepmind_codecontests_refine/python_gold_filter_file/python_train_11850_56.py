N, M = map(int, input().split())
g = []
for i in range(1,M+1):
  if M%i==0:
    j = M//i
    if i<=M//N:
      g += [i]
    if j<=M//N:
      g += [j]
  if i>M**0.5:
    break
print(max(g))