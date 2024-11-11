N, M = map(int, input().split())
a = list(map(int, input().split()))
bc = [tuple(map(int, input().split())) for _ in range(M)]
bc.sort(key=lambda x: x[1], reverse=True)
rest = N
for b, c in bc:
  a += [c] * min(rest, b)
  rest -= min(rest, b)
a.sort(reverse=True)
print(sum(a[:N]))