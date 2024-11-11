S = input()
T = input()

len_S = len(S)
len_T = len(T)
for i in range(len_S-len_T, -1, -1):
  if not all(s in ['?', t] for s, t in zip(S[i:i+len_T], T)):
    continue
  print((S[:i] + T + S[i+len_T:]).replace('?','a'))
  exit()
print("UNRESTORABLE")
