N, K = map(int,input().split())

history = [0] * (K + 1)
total = 0

divide = pow(10, 9) + 7

for i in range(K, 0, -1):
  history[i] = pow(K//i, N, divide)
  for j in range(2, K//i + 1):
    history[i] -= history[i * j]
  total += ((i * history[i]) % divide)
  
total = total % divide
print(total)
