P=10**9+7
N=int(input())
S1=input()
S2=input()
L=[1]
k=0
P=10**9+7
for i in range(1,N):
    if S1[i]!=S1[i-1]:
        L.append(0)
        k+=1
    L[k]+=1
M=len(L)
S=1
if L[0]==1:
    S=3
else:
    S=6
for i in range(1,M):
    if L[i-1]==1:
        S=(S*2)%P
    else:
        if L[i]==2:
            S=(S*3)%P
print(S)
