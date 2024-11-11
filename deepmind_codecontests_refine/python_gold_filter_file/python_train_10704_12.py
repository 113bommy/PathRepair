N=int(input())
S=input()
DP=[0]*N
l=0
for i,x in enumerate(S):
  DP[i]+=l
  if x=="E":
    l+=1
r=0
for i,y in enumerate(S[::-1]):
  DP[N-1-i]+=r
  if y=="W":
    r+=1
print(N-1-max(DP))