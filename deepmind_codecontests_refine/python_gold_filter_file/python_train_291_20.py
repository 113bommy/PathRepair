import sys
input=sys.stdin.readline
sys.setrecursionlimit(10**7)

N,M=map(int,input().split())

L=[[]for i in range(N+1)]
D=dict()
for i in range(M):
    l,r,d=map(int,input().split())
    L[l].append([r,d])
    L[r].append([l,-d])
    D[i]=(l,r,d)
    
C=["N" for i in range(N+1)]

def dfs(x):
    for i,j in L[x]:
        if C[i]=="N":
            C[i]=C[x]+j
            dfs(i)

for i in range(1,N+1):
    if C[i]=="N":
        C[i]=0
        dfs(i)
#print(C)
#print(D)
for i in range(M):
    l,r,d=D[i]
    if C[r]-C[l]!=d:
        print("No")
        exit()
print("Yes")