n = int(input())
a = input()
A = [ch for ch in a]
remove = -1

for i in range(n-1):
  if ord(A[i])>ord(A[i+1]):
    remove = i
    break
def removal(a,k):
  return ''.join([a[i] for i in range(len(a)) if i != k])
if remove == -1:
  print(a[:-1])
else:
  print(removal(a,remove))
