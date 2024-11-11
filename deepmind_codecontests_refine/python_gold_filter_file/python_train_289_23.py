S = input()
str = "keyence"
frag = False

for a in range(0,len(S)):
  if (S[0:a] + S[a - 7:]) == str:
    frag = True

if frag:
  print("YES")
else:
  print("NO")