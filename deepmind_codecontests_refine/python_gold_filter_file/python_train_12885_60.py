S=input()
T=input()
k=0
for i in range(len(S)):
  if S[i]!=T[i]:
    k+=1
print(k)