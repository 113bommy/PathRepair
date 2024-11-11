n = int(input())
k = 1
for i in range(1,n+1):
  k = k*i%(10**9+7)
print(k)
