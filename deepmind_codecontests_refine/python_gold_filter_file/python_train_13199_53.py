N = int(input())
a = 1
while a * a <= N:
  if N % a == 0:
    k = a
  a += 1
b = N //k
print(b + k - 2)
