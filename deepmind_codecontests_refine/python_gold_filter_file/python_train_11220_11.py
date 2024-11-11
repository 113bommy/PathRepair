n = input()
A = list(map(int,input().split()))
s = 1
A.sort()
for a in A:
  s *= a
  if s > 10**18:
    s = -1
    break
print(s)