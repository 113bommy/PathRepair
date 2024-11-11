S=input()
T=input()
P=0
for i in range(len(S)):
  if S[i]!=T[i]:
    P+=1
print(P)
