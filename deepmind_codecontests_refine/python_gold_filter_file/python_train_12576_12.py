import sys
input = sys.stdin.readline
N = int(input())
res = 0
a = 0
b = 0
ab = 0
for _ in range(N):
  s = input()[: -1]
  res += s.count("AB")
  a += s[-1] == "A"
  b += s[0] == "B"
  ab += (s[-1] == "A" and (s[0] == "B"))
ab = ab > 0 and (a == b == ab)
print(res + min(N - 1, a - ab, b - ab))