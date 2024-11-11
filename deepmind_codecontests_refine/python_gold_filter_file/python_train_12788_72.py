A, B, C, D, E, F = map(int, input().split())
Swater, sugar, percent = 100*A, 0, 0
for k in range(F//(100*A) + 1):
  for l in range(F//(100*B) + 1):
    if k == 0 and l == 0:
      continue
    M = k*A + l*B
    if 100 * M > F:
      continue
    for x in range(M*E//C + 1):
      for y in range(M*E//D + 1):
        S = C*x + D*y
        if 100*M+S > F:
          continue
        if S > M*E:
          continue
        t = 100*S / (100*M+S)
        if t > percent:
          percent = t
          Swater = 100*M+S
          sugar = S
print(Swater, sugar)