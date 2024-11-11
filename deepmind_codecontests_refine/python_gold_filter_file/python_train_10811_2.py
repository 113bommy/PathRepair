N = int(input())
S = input()

ans = 0
x = 0
for s in S:
  v = 1 if s == 'I' else -1
  x += v
  ans = max(ans, x)
print(ans)
