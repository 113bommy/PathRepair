n = int(input())
a, h = [0 for _ in range(101)], [0 for _ in range(101)]
for i in range(n):
  _a, _h = map(int, input().split())
  a[_a] += 1
  h[_h] += 1
print(sum([a[i] * h[i] for i in range(101)]))