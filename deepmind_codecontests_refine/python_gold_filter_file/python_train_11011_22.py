n,k=map(int,input().split())
A=list(map(int,input().split()))
C=[n for _ in range(n)]

while k!=0:
    B=[0 for _ in range(n+1)]
    for i,j in enumerate(A):
        B[max(0,i-j)] +=1
        B[min(n,i+j+1)] -=1
    for i in range(1,n):
        B[i] +=B[i-1]
    A=B[:n]
    k -=1
    if A==C:break
print(*A)