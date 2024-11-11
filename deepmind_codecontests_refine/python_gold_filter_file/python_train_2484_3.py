import math

N=int(input())
A=[int(input()) for _ in range(N)]
#print(A)

B=0
for a in A:
  B^=a

C=[]
D=[0]*100
for a in A:
  C.append(bin(a^(a-1))[2:])
#print(C)
for c in C:
  D[len(c)]=1
#print(D)

ans=0
while B:
  #print(B,bin(B))
  if D[len(bin(B)[2:])]:
    B^=2**len(bin(B)[2:])-1
    ans+=1
  else:
    ans=-1
    break
print(ans)  