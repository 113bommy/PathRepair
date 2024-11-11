N=int(input())
S=input()
ans=1
for x in range(N-1):
  if S[x]!=S[x+1]:
    ans +=1
print(ans)