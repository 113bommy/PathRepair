N=int(input())
S=input()
DP=[0]*N
l=0
for i,x in enumerate(S):
  DP[i]+=l
  if S[i]=="W":
      l+=1
r=0
for j,y in enumerate(S[::-1]):
  DP[N-1-j]+=r
  if S[N-1-j]=="E":
      r+=1
print(min(DP))