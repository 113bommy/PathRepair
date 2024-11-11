N = int(input())
S = input()
ans = ''
for s in S:
  ans += chr(((ord(s)-65+N)%26)+65)
print(ans)