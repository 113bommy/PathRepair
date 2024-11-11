N=int(input())
S=input()
ans=0
tmp=0
for k in range(N):
  for j in range(k):
    i=2*j-k
    if i>=0:
      if S[i]!=S[j] and S[i]!=S[k] and S[j]!=S[k]:
        tmp+=1
ans=S.count("R")*S.count("G")*S.count("B")-tmp
print(ans)

      
      
    