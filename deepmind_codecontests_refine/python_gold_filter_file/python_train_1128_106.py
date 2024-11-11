N = int(input())
A = list(map(int, input().split()))
c = 0
s = set()

for a in A:
  if a >= 3200:
    c += 1
  else:
    s.add(a//400)
print(max(1, len(s)), len(s) + c)