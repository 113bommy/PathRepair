S = input()
N = len(S)
 
for i in range(7+1):
  if S[:i] + S[i+N-7:] == "keyence":
    print("YES")
    exit()
print("NO")