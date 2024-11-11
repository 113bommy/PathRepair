S=input()
l=len(S)
a=0
for i in range(l):
  for j in range(i,l):
    if S[:i]+S[j:]=="keyence":
      a=1
print(["NO","YES"][a])
