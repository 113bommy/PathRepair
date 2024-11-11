import sys
input = sys.stdin.readline
N = int(input())
i = 2
x = N + 0
s = set()
while i * i <= N:
  while x % i == 0:
    x //= i
    s.add(i)
  i += 1
if x > 1 and x != N:
  s.add(x)
if len(s) == 0:
  print(N)
elif len(s) == 1:
  print(s.pop())
else:
  print(1)