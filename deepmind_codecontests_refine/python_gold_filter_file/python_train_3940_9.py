N = int(input())
K = int(input())
c = 1
for i in range(N):
  c = min(c*2, c+K)
print(c)