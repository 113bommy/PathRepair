s=input()
K=int(input())

S=[]
n=len(s)
for i in range(n):
  for j in range(i+1,i+K+1):
    S.append(s[i:j])
S=list(set(S))
S.sort()
print(S[K-1])