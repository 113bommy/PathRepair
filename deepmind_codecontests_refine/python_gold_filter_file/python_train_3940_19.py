N = int(input())
K = int(input())
c = 1
for _ in range(N):
  c = min(2*c, c+K)
print(c)