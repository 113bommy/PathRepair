*inputs, = map(int, open(0).read().split())
A = inputs[:9]
B = inputs[9:]

C = [0] * 9
for b in B:
  if b in A:
    C[A.index(b)] = 1
    
if any([
     all(C[:3]), all(C[3:6]), all(C[6:]),
     all(C[::3]), all(C[1::3]), all(C[2::3]),
     all([C[0], C[4], C[8]]), all([C[2], C[4], C[6]])
    ]):
  print('Yes')
else:
  print('No')