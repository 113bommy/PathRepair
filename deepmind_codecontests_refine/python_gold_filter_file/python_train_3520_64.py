N=int(input())
A=list(map(int,input().split()))

DPLIST=[[None]*N for i in range(N)]

SUM=[0]
for i in range(N):
    DPLIST[i][i]=0
    SUM.append(SUM[-1]+A[i])

for i in range(1,N):
    for j in range(i,N):

        ANS=float("inf")

        for k in range(j-i,j):

            if ANS>DPLIST[j-i][k]+DPLIST[k+1][j]+SUM[j+1]-SUM[j-i]:
                ANS=DPLIST[j-i][k]+DPLIST[k+1][j]+SUM[j+1]-SUM[j-i]
        
        DPLIST[j-i][j]=ANS

print(DPLIST[0][N-1])
