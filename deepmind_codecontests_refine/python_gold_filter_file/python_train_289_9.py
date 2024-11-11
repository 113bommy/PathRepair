S = input()

bl = False
for L in range(8):
  T = S[:L] + S[len(S)-(7-L):]
  if T == 'keyence':
    bl = True
    break

answer = 'YES' if bl else 'NO'
print(answer)