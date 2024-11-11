s=input()
x=len(s)-7
for i in range(7):
  if s[:i]+s[x+i:] == "keyence":
    print("YES")
    break
else:
  print("NO")