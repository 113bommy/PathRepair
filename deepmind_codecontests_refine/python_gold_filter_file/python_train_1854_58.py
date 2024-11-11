S = input()
for i in range(1,4):
  if S[i]==S[i-1]:
    print('Bad')
    exit()
print('Good')