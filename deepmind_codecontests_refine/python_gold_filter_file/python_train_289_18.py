S = input()
for i in range(len(S)-5):
  S_cut = S[:i]+S[i+len(S)-7:]
  #print(S_cut)
  if S_cut=='keyence':
    print('YES')
    exit()
print('NO')