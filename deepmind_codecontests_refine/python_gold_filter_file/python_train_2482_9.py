import re
S=input().replace("?", ".")
T=input()
ans=[]
moji = len(T)
for i in range(len(S)-len(T)+1):
  m = re.search(S[i:moji+i], T)
  if m is not None:
    ans.append((S[0:i] + T + S[i+moji:]).replace(".", "a"))

if ans:
  print(sorted(ans)[0])
else:
  print("UNRESTORABLE")