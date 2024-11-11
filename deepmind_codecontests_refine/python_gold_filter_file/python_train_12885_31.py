S=input()
T=input()
aa=0
for s,t in zip(S,T):
  if s!=t:
    aa+=1
print(aa)