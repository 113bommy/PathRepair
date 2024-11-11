N = int(input())
r = 0
nBA = 0
nA = 0
nB = 0
for i in range(N):
  s = input()
  r += s.count("AB")
  if s[0] == "B" and s[-1] == "A":
    nBA += 1
  elif s[0] == "B":
    nB += 1
  elif s[-1] == "A":
    nA += 1
r += min(nA, nB)
if nA > 0 or nB > 0:
  r += nBA
else:
  r += max(0, nBA-1)
print(r)
