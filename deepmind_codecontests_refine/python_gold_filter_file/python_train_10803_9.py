n = int(input())
c = 0
for p in range(2, int(n**0.5)+1): #nが合成数
  e = 0
  while n%p == 0:
    n //= p
    e += 1
  i = 1
  while e >= i:
    e -= i
    c += 1
    i += 1
if n != 1: #nが素数
  c += 1
print(c)