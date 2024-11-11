N=int(input())
L=list(map(int,input().split()))
MAX=0
ANS=[]
for i in range(N):
    B=L[:]
    for j in range(i-1,-1,-1):
        B[j]=min(B[j],B[j+1])
    for j in range(i+1,N):
        B[j]=min(B[j],B[j-1])
    S=sum(B)
    if S>MAX:
        MAX=S
        ANS=B[:]
print(*ANS)