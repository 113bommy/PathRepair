N,K = list(map(int, input('').split(' ')))
D = set()
for i in range(K):
  input('')
  D |= set(map(int, input('').split(' ')))
print(N-len(D))