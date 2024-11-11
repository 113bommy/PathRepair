N=int(input())
S=list(input())
p=0


for i in range(N-1):
  if S[i]==S[i+1]:
    N-=1

print(N)