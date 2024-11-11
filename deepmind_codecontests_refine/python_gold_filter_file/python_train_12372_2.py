N=int(input())
inf=float("inf")
A=[list(map(int,input().split())) for _ in range(N)]

def calc():
    ans=0
    for i in range(N):
        for j in range(N):
            used=True
            for k in range(N):
                if i==k or k==j:continue
                if A[i][j]>A[i][k]+A[k][j]:
                    return -1
                elif A[i][j]==A[i][k]+A[k][j]:
                    used=False
            if used:
                ans+=A[i][j]
    return ans//2
                
print(calc())