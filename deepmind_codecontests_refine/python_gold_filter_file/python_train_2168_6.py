S = input()
T = input()
s = []
t = []
for alp in "abcdefghijklmnopqrstuvwxyz":
  s.append(S.count(alp))
  t.append(T.count(alp))
if(sorted(s) == sorted(t)):
  print("Yes")
else:
  print("No")