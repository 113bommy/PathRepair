N = int(input())
S = input()
ans = ""
for s in S:
  ans += chr((ord(s) + N-65)%26 + 65)
print(ans)