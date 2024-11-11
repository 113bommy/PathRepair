N=int(input())
S=input()
n=0
for i in range(N-1):
  if S[i]==S[i+1]:
    n+=1
print(N-n)