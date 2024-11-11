N = int(input())
m = 1
for i in range(2,N+1):
  m = m*i%(10**9+7)
print(m)