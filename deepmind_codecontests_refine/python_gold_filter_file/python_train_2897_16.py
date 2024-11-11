N=int(input())
S=[list(input()) for i in range(N)]
def issym(IL):
    for i in range(N):
        for j in range(i+1,N):
            if IL[i][j]!=IL[j][i]:
                return False
    return True
def changelist(A,B):
    T=[["" for i in range(N)] for j in range(N)]
    for i in range(N):
        for j in range(N):
            T[i][j]=S[(i+A)%N][(j+B)%N]
    return T
ans=0
for i in range(N):
    L=changelist(i,0)
    if issym(L):
        ans+=N
print(ans)
