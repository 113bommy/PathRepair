S=input()
a=0
for i in range(len(S)-2):
  if S[i]==S[i+1] or S[i]==S[i+2] or S[i+1]==S[i+2]:
    a=1
    print(i+1,i+3)
    break

if a==0:
 if len(S)>1 and S[-1]==S[-2]:
  print(len(S)-1,len(S))
 else:
  print(-1,-1)

