N=int(input())
A=list(map(int,input().split()))

DPLIST=[[None]*N for i in range(N)]

for i in range(N):
    DPLIST[i][i]=[0,A[i]]

for i in range(1,N):
    for j in range(i,N):
        #print(i,j)
        ANS=float("inf")
        slime=float("inf")

        for k in range(j-i,j):
            sc1,sl1=DPLIST[j-i][k]
            sc2,sl2=DPLIST[k+1][j]

            if ANS>sc1+sc2+sl1+sl2:
                ANS=sc1+sc2+sl1+sl2
                slime=sl1+sl2
        
        DPLIST[j-i][j]=[ANS,slime]

    #print(DPLIST)
    #print()
            

print(DPLIST[0][N-1][0])