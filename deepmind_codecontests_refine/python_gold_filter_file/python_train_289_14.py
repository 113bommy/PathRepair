S = input()
key = "keyence"
for i in range(len(key)+1):
  if key == S[:i] + S[len(S)-len(key)+i:]:
    print("YES")
    break
else:
  print("NO")
