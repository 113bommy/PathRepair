n,m,k=map(int,input().split())
A=list(map(int,input().split()))
A.sort(reverse=True)

M1=A[0]
M2=A[1]

print(M2*(m//(k+1))+M1*(m-(m//(k+1))))
