N=int(input())
S=input()
c=1
for i in range(1,N):
  if S[i-1]!=S[i]:
    c+=1
print(c)