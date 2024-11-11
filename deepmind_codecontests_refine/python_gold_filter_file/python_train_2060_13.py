N = input()
L=len(N)

DP=[[N]*2 for _ in range(L+1)]
DP[0][0]=0
DP[0][1]=1

for i,n in enumerate(N,1):
    DP[i][0]= min(DP[i-1][0]+int(n),DP[i-1][1]+10-int(n))
    DP[i][1] = min(DP[i-1][0]+int(n)+1,DP[i-1][1]+9-int(n))

print(DP[L][0])
