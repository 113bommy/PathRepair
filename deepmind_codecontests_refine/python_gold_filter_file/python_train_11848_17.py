N=int(input())
A=list(map(int,input().split()))
B=list(map(int,input().split()))
ans=min(A[0],B[0])
B[0]-=ans
for i in range(N-1):
    score=min(A[i+1],B[i]+B[i+1])
    ans+=score
    B[i+1]-=max(0,score-B[i])
print(ans+min(B[N-1],A[N]))