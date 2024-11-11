s, t = input().split()
a, b = map(int, input().split())
k = input()
if s == k:
  a -= 1
else:
  b -= 1
print(a, b)