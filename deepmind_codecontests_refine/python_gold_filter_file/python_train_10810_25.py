S=input()
for i in range(len(S)-1):
  S=S[:-1]
  N=len(S)//2
  if S==S[:N]*2:
    print(N*2)
    exit()
print(1)