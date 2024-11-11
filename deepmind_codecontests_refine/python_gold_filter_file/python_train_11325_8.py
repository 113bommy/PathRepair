import math

z = 10**9 + 7

n, a, b = [int(i) for i in input().split()]

r = pow(2, n, z) - 1

def c(m):
  x = 1
  for i in range(n-m+1, n+1):
    x = x*i % z
  
  return (x * pow(math.factorial(m), z-2, z)) % z

r = (r - c(a) - c(b)) % z

print(r)