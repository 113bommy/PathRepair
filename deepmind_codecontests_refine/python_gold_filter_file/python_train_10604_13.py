S = input()
T = "CODEFESTIVAL2016"
c = 0
for i in range(16):
  if S[i]!=T[i]:
    c += 1
print(c)