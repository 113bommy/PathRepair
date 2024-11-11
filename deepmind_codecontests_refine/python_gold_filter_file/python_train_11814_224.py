
M,N=input().split()
M=int(M)
N=int(N)

if M%2==0:
    ans=M//2*N
else:
    ans=M//2*N+N//2

print(ans)