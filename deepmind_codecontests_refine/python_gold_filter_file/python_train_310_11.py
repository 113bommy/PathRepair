def is_prime(n):
  for i in range(2, int(n ** 0.5) + 1):
    if n % i == 0: return False
  return True

count = 0
for i in range(int(input())):
  if is_prime(int(input())) : count += 1
print(count)