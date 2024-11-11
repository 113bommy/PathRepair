def find(x):
  if P[x] < 0:
    return x
  else:
    return find(P[x])

N, M, *X = map(int,open(0).read().split())
P = [-1] * (N + 1)
S = N * (N - 1) // 2
r = [S]

while X:
  b, a = find(X.pop()), find(X.pop())
  if a != b:
    S -= P[a] * P[b]
    if P[a] > P[b]:
      a, b = b, a
    P[a] += P[b]
    P[b] = a
  r.append(S)

r.pop()
print(*reversed(r), sep='\n')