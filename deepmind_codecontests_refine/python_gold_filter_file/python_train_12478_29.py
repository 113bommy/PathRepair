N=int(input())
S,T=input(),input()

cnt=0
for i in range(N):
  if S[i:]==T[:N-i]:
    cnt=N-i
    break
print(len(S)+len(T)-cnt)