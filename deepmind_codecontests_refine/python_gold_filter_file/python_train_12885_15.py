S = input()
T = input()
a = 0

for s,t in zip(S,T):
  if s!=t:
    a+=1

print(a)