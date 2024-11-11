n = int(input())
s = 1
for i in range(1,n+1):
  s *= i
  s %= 1000000007
print((s+1000000007-pow(2,n-1, 1000000007))%1000000007)
