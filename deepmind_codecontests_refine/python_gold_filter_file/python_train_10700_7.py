n,k=map(int,input().split())
A=list(map(int,input().split()))
m=M=sum(A[:k])
for i in range(n-k):
    m=m-A[i]+A[i+k]
    M=max(M,m)
print((M+k)/2)