n = list(input())
s = sorted(input())[::-1]

s_index = 0

for i, nn in enumerate(n):
  if s_index >= len(s):
    break

  if int(nn) < int(s[s_index]):
    n[i] = s[s_index]
    s_index += 1
  
print("".join(n))
