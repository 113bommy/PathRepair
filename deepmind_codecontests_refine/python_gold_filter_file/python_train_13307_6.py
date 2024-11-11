import itertools as ite
N=int(input())
C=[0]*6
J="MARCH"
for i in range(N):
    C[J.find(input()[0])]+=1
ans=0
for i,j,k in list(ite.combinations(range(5),3)):
    ans+=C[i]*C[j]*C[k]
print(ans)
