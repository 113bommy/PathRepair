import sys
input = sys.stdin.readline
t = int(input())
for _ in range(t):
  n = int(input())
  s = input()
  f = int(s[0])
  l = int(s[1:])
  if f >= l:
    print("NO")
  else:
    print("YES")
    print(2)
    print(f,l)