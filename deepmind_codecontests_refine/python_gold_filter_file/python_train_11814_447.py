M,N=input().split()
M=int(M)
N=int(N)

print(int((N*M)/2) if (N*M)%2==0 else int(((M*N)-1)/2))